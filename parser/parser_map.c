/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:16:35 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/14 19:34:53 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
static bool ft_get_player_orient(t_apin *data, t_parser *parser)
{
	PARCOURIR LE TABLEAU 2D
}
static void ft_map_build(t_apin *data, t_parser *parser)
{
	t_map_lst *cur_lst;
	size_t i;

	data->map = ft_calloc(data->height + 1, sizeof (char*));
	cur_lst = parser->map_lst;
	i = 0;
	while(cur_lst->next != NULL)
	{
		data->map[i] = ft_calloc(data->width + 1, sizeof(char));
		ft_strlcpy(data->map[i], cur_lst->content, ft_strlen(cur_lst->content));
		i++;
		cur_lst = cur_lst->next;
	}
	BUILD MAP AVEC DES ESPACE
}

static void ft_map_get_width_height(t_apin *data, t_parser *parser)
{
	size_t i;
	t_map_lst *cur_lst;

	i = 1;
	cur_lst = parser->map_lst;
	while(cur_lst != NULL)
	{
		i++;
		cur_lst = cur_lst->next;
	}
	data->height = i;
	i = 0;
	cur_lst = parser->map_lst;
	while(cur_lst != NULL)
	{
		if(ft_strlen(cur_lst->content) > i)
			i = ft_strlen(cur_lst->content);
		cur_lst = cur_lst->next;
	}
	data->width = i;
}
/*GNL the map into a list*/
static void	ft_map_to_lst(t_parser *parser)
{
	char *gnl;

	parser->map_lst = ft_maplstnew(parser->last_gnl);
	gnl = get_next_line(parser->fd);
	
	while(gnl != NULL)
	{
		ft_maplstadd_back(&parser->map_lst, ft_maplstnew(gnl));
		gnl = get_next_line(parser->fd);
	}
}

/*Build the map in a 2D array*/
bool ft_parser_map(t_apin *data, t_parser *parser)
{
	ft_map_to_lst(parser);
	ft_map_get_width_height(data, parser);
	ft_map_build(data, parser);

	for(size_t i = 0; data->map[i]; i++)
	{
		printf("%s\n", data->map[i]);
	}
	return (true);
}