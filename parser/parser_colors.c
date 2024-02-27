/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:07:54 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/27 17:14:35 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*Take the RGB int to convert into one int for MLX*/
void ft_convert_rgb_int(t_parser *parser, t_apin *data, char *gnl_str)
{
	int	temp_int;
	
	temp_int = 0 << 24 | parser->color_red << 16 | parser->color_green << 8 | parser->color_blue;
	if(gnl_str[0] == 'C')
	{
		data->top = temp_int;
		free(parser->color_top);
	}
	if(gnl_str[0] == 'F')
	{
		data->bottom = temp_int;
		free(parser->color_bottom);
	}
}
/*Check the color line, the number of comma, the presence of only digits or comma or spaces, atoi it, then convert to int for mlx then return true*/
bool ft_check_get_color(t_parser *parser, t_apin *data, char *cur_attrib, char *gnl_str)
{
	size_t i;
	size_t comma;

	comma = 0;
	i = 0;
	while (cur_attrib[i])
	{
		if (ft_isdigit(cur_attrib[i]) == 0 && cur_attrib[i] != ',' && cur_attrib[i] != ' ') //Check if only digit comma and spaces
			return(false);
		if (cur_attrib[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (false);
	parser->color_red = ft_atoi(cur_attrib);
	if(cur_attrib[0] == ',' || parser->color_red < 0 || parser->color_red > 255)
		return(false);
	parser->color_green = ft_atoi(ft_strchr(cur_attrib, ',') + 1);
	if(*(ft_strchr(cur_attrib, ',') + 1) == ',' || parser->color_green < 0 || parser->color_green > 255)
		return(false);
	parser->color_blue = ft_atoi(ft_strrchr(cur_attrib, ',') + 1);
	if(*(ft_strrchr(cur_attrib, ',') + 1) == '\0' || parser->color_blue < 0 || parser->color_blue > 255)
		return(false);
	return(ft_convert_rgb_int(parser, data, gnl_str), true);
}
