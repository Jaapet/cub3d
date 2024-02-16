/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:47:33 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/15 18:55:18 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cub3d.h"
// #include <stdbool.h>

/*Check syntax of the cub3d args, return true if args ar ok, check also if
the .cub is available*/
bool ft_parser_args(int ac, char** av, t_parser *parser_data)
{
	if (ac != 2)
		return(ft_perror("incorrect args number\n"), false);
	parser_data->fd = open(av[1], O_RDONLY);
	if (parser_data->fd == -1)
		return(ft_perror("cannot acess the file\n"), false);
	return (true);
}