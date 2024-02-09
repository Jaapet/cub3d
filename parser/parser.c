/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:42:33 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/09 18:43:10 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cub3d.h"

/*main func of the parser, will return true in case of correct parsing, 
false with an error msg in case of a parsing error.
This func will no free the t_apin struct or exit the program*/
bool ft_parser(int ac, char **av, t_apin *data){
	t_parser parser_data;
	
	ft_bzero(&parser_data, sizeof(parser_data));
	return (true);
}