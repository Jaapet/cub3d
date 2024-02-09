/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:41:09 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/09 18:27:12 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdbool.h>

// Struct used by the parser, not reused after the parser
typedef struct s_parser{
	int fd;
	size_t attributes_parsed;
	char *color_top;
	char *color_bottom;
} t_parser;

#endif