/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:07:54 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/11 15:02:22 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*Take the RGB int to convert into one int for MLX*/
void	ft_convert_rgb_int(t_parser *parser, t_apin *data, char *gnl_str)
{
	int	temp_int;

	temp_int = 0 << 24 | parser->r << 16
		| parser->g << 8 | parser->b;
	if (gnl_str[0] == 'C')
	{
		data->top = temp_int;
		free(parser->color_top);
	}
	if (gnl_str[0] == 'F')
	{
		data->bottom = temp_int;
		free(parser->color_bottom);
	}
}

/*Check the color line, the number of comma, the presence of only digits or
comma or spaces, atoi it, then convert to int for mlx then return true*/
bool	ft_check_get_color(t_parser *p, t_apin *d, char *c, char *s)
{
	size_t	i;
	size_t	comma;

	comma = 0;
	i = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]) == 0 && c[i] != ',' && c[i] != ' ')
			return (false);
		if (c[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (false);
	p->r = ft_atoi(c);
	if (c[0] == ',' || p->r < 0 || p->r > 255)
		return (false);
	p->g = ft_atoi(ft_strchr(c, ',') + 1);
	if (*(ft_strchr(c, ',') + 1) == ',' || p->g < 0 || p->g > 255)
		return (false);
	p->b = ft_atoi(ft_strrchr(c, ',') + 1);
	if (*(ft_strrchr(c, ',') + 1) == '\0' || p->b < 0 || p->b > 255)
		return (false);
	return (ft_convert_rgb_int(p, d, s), true);
}
