/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_attributes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:23:37 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/14 18:10:42 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cub3d.h"

/* isolate the path OR the color value of the attribute*/
static char *ft_get_path_attribute(char *str)
{
	size_t i;

	char *out_str;
	i = 0;
	while(str[i] != ' ')
		i++;
	while(str[i] == ' ')
		i++;
	out_str = ft_strdup(str + i);
	out_str[ft_strlen(out_str) - 1] = '\0';
	return(out_str);
}


/*Check if the path of the files are a good path or a valide RGB color*/
static bool ft_valid_attrib(t_parser *parser, t_apin *data, char *cur_attrib, char *gnl_str)
{
	int tmp_fd;
	
	if(gnl_str[0] == 'F' || gnl_str[0] == 'C')
	{
		if(ft_check_get_color(parser, data, cur_attrib, gnl_str) == true)
			return(true);
		else
			return(perror("invalid color"), false);
	}
	else
	{
		tmp_fd = open(cur_attrib, O_RDONLY);
		if(tmp_fd > 0)
		{
			close(tmp_fd);
			return(true);
		}
		else
			return(perror("invalid texture file"), false);
	}
}
/*Search the current attribute of the GNL line, if a non duplicate attribute is found put a flag to true and return true, else return false*/
static bool ft_check_attrib(char *str_gnl, char *attrib, bool *attrib_flag)
{
	if(*attrib_flag == true)
		return(false);
	if(ft_strncmp(str_gnl, attrib, ft_strlen(attrib) + 1))
	{
		*attrib_flag = true;
		return(true);
	}
	return(false);
}
/*Process each line of the conf file*/
static bool ft_attrib_process(t_parser *parser_data, t_apin *data, char *str)
{
	char **current_attribute;

	current_attribute = NULL;
	if (str[0] == '\0' || ft_is_begin_of_map(str))
		return(true);
	else if (ft_check_attrib(str, "NO ", &parser_data->NO_attrib))
		current_attribute = &data->p_wall_n;
	else if (ft_check_attrib(str, "SO ", &parser_data->SO_attrib))
		current_attribute = &data->p_wall_s;
	else if (ft_check_attrib(str, "EA ", &parser_data->EA_attrib))
		current_attribute = &data->p_wall_e;
	else if (ft_check_attrib(str, "WE ", &parser_data->WE_attrib))
		current_attribute = &data->p_wall_w;
	else if (ft_check_attrib(str, "C ", &parser_data->C_attrib))
		current_attribute = &parser_data->color_top;
	else if (ft_check_attrib(str, "F ", &parser_data->F_attrib))
		current_attribute = &parser_data->color_bottom;
	else
		return(false);
	*current_attribute = ft_get_path_attribute(str);
	if (ft_valid_attrib(parser_data, data, *current_attribute, str) == true)
		parser_data->attributes_parsed++;
	return(true);
}
/*Check check each lines in search of an attribute*/
bool ft_parser_attributes(t_parser *parser_data, t_apin *data)
{
	char *temp_str;
	bool not_started;

	not_started = true;
	parser_data->attributes_parsed = 0;
	while(not_started || ft_is_begin_of_map(temp_str) != true)
	{
		free(temp_str);
		not_started = false;
		temp_str = get_next_line(parser_data->fd);
		if (temp_str == NULL)
			return(perror("file ended unexpectedly"), false);
		if (ft_attrib_process(parser_data, data, temp_str) == false)
			return(free(temp_str), perror("invalid attribute on map or invalid begin of map\n"), false);	
	}
	if (parser_data->attributes_parsed != 6)
	{
		if (parser_data->color_bottom != NULL)
			free(parser_data->color_bottom);
		if (parser_data->color_top != NULL)
			free(parser_data->color_top);
		return(perror("invalid .cub file\n"), false);
	}
	parser_data->last_gnl = temp_str;
	return(true);
}
