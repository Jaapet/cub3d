/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:09:58 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/10 21:20:44 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


/*Print text in fd 2*/
void ft_perror(char *str)
{
	write(2, &"Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, &"\n", 1);
}
/*Check if the current line is the beginining of the map 
(it only contain WS and 1 char) return true if its the begining*/
bool ft_is_begin_of_map(char *gnl_str)
{
	size_t i;

	i = 0;
	while (gnl_str[i])
	{
		if (gnl_str[i] != ' ' && gnl_str[i] != '1' && gnl_str[i] != '\n')
			return (false);
		i++;
	}
	if(gnl_str[0] == '\n')
		return (false);
	return (true);
}
/*modified strncpy for adding white space on empty char, end the str with a ws and start with a ws*/
size_t	ft_strlcpy_map(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	dst[0] = ' ';
	if (size > 0)
	{
		while ((src[i] && i < size - 1) && size != 0)
		{
			if (src[i] != '\n')
				dst[i + 1] = src[i];
			else
				dst[i + 1] = ' ';
			i++;
		}
		while (i < size - 1)
		{
			dst[i + 1] = ' ';
			i++;
		}
		dst[i + 1] = 0;
	}
	return (ft_strlen(src));
}
