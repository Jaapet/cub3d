/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_attributes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:23:37 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/09 20:19:22 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cub3d.h"

/*Check if the current line is the beginining of the map 
(it only contain WS and 1 char) return true if its the begining*/

static bool ft_is_begin_of_map(t_parser *parser_data, char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			return (false);
		i++;
	}
	return (true);
}
/* isolate the path OR the color value of the attribute*/
static char *ft_get_path_attribute(char *str)
{
	size_t i;

	i = 0;
	while(str[i] != ' ')
		i++;
	while(str[i] == ' ')
		i++;
	return(ft_strdup(str + i));
}ATTENTION DOUBLE ATTRIB
/*Check if the path of the files are a good path or a valide RGB color*/
static bool ft_valid_attrib(t_parser *parser, char *cur_attrib, char *gnl_str)
{
	if(gnl_str[0] == 'F' || gnl_str[0] == 'C')
	{

	}
	else
	{
		open
	}
}
/*Process each line of the conf file*/
static bool ft_attrib_process(t_parser *parser_data, t_apin *data, char *str)
{
	char *current_attribute;

	current_attribute = NULL;
	if (str[0] == '\0')
		return(true);
	else if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		current_attribute = data->p_wall_n;
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		current_attribute = data->p_wall_s;
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		current_attribute = data->p_wall_w;
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		current_attribute = data->p_wall_e;
	else if (str[0] == 'F' && str[1] == ' ')
		current_attribute = parser_data->color_bottom;
	else if (str[0] == 'C' && str[1] == ' ')
		current_attribute = parser_data->color_top;
	else
		return(false);
	current_attribute = ft_get_path_attribute(str);
	parser_data->attributes_parsed++;
	return(true);

}
/*Check check each lines in search of an attribute*/
bool ft_parser_attributes(t_parser *parser_data, t_apin data)
{
	char *temp_str;

	parser_data->attributes_parsed = 0;
	while(ft_is_begin_of_map(parser_data, temp_str) != true)
	{
		temp_str = get_next_line(parser_data->fd);
		if (ft_attrib_process(parser_data, &data, temp_str) == false)
			return(free(temp_str), perror("invalid attribute on map\n"), false);
		free(temp_str);
	}
	if (parser_data->attributes_parsed != 6)
	{
		if (parser_data->color_bottom != NULL)
			free(parser_data->color_bottom);
		if (parser_data->color_top != NULL)
			free(parser_data->color_top);
		return(perror("invalid .cub file\n"), false);
	}
		
	return(true);
}