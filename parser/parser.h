/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:41:09 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/11 15:02:22 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include "../cub3d.h"

typedef struct s_apin	t_apin;
// Struct for the map lst, temporary not reused after
typedef struct s_map_lst
{
	struct s_map_lst	*next;
	char				*content;
}	t_map_lst;

// Struct used by the parser, not reused after the parser
typedef struct s_parser
{
	//FD of the map for GNL
	int			fd;

	// Attributes for the parsing
	size_t		attributes_parsed;
	bool		no_attrib;
	bool		so_attrib;
	bool		we_attrib;
	bool		ea_attrib;
	bool		f_attrib;
	bool		c_attrib;

	// Temp ptr, to free when the parsing of the color is done
	char		*color_top;
	char		*color_bottom;

	// Temp int for RGB
	int			r;
	int			g;
	int			b;

	// Last GNL
	char		*last_gnl;
	// Map lst
	t_map_lst	*map_lst;
}	t_parser;

//Colors
void		ft_convert_rgb_int(t_parser *parser, t_apin *data, char *gnl_str);
bool		ft_check_get_color(t_parser *parser, t_apin *data,
				char *cur_attrib, char *gnl_str);
//Utils lst
t_map_lst	*ft_maplstnew(char *content);
t_map_lst	*ft_maplstlast(t_map_lst *lst);
void		ft_maplstadd_back(t_map_lst **lst, t_map_lst *new);
void		ft_mapls_free(t_map_lst *lst);
//Utils
bool		ft_is_begin_of_map(char *gnl_str);
size_t		ft_strlcpy_map(char *dst, const char *src, size_t size);

bool		ft_parser_args(int ac, char **av, t_parser *parser_data);
bool		ft_parser_attributes(t_parser *parser_data, t_apin *data);
bool		ft_parser_map(t_apin *data, t_parser *parser);

void		ft_get_player_pos(t_apin *data);
bool		ft_map_illegal_char(t_apin *data);
bool		ft_map_is_closed(t_apin *data);
bool		ft_is_player(char c);
#endif