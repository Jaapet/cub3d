/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:16:35 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/11 14:41:11 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	ft_get_player_ori(t_apin *data)
{
	size_t	i;
	size_t	j;

	data->start_ori = '\0';
	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (ft_is_player(data->map[j][i]))
			{
				if (data->start_ori == '\0')
					data->start_ori = data->map[j][i];
				else
					return (ft_perror("duplicated player"), false);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (data->start_ori == '\0')
		return (ft_perror("no player found"), false);
	return (true);
}

static void	ft_map_build(t_apin *data, t_parser *parser)
{
	t_map_lst	*cur_lst;
	size_t		i;

	data->map = ft_calloc(data->height + 2, sizeof(char *));
	data->map[0] = ft_calloc(data->width + 2, sizeof(char));
	ft_memset(data->map[0], ' ', data->width + 1);
	cur_lst = parser->map_lst;
	i = 1;
	while (cur_lst != NULL)
	{
		data->map[i] = ft_calloc(data->width + 2, sizeof(char));
		ft_strlcpy_map(data->map[i], cur_lst->content, data->width + 1);
		i++;
		cur_lst = cur_lst->next;
	}
	data->map[i] = ft_calloc(data->width + 2, sizeof(char));
	ft_memset(data->map[i], ' ', data->width + 1);
	ft_mapls_free(parser->map_lst);
}

static void	ft_map_get_width_height(t_apin *data, t_parser *parser)
{
	size_t		i;
	t_map_lst	*cur_lst;

	i = 1;
	cur_lst = parser->map_lst;
	while (cur_lst != NULL)
	{
		i++;
		cur_lst = cur_lst->next;
	}
	data->height = i;
	i = 0;
	cur_lst = parser->map_lst;
	while (cur_lst != NULL)
	{
		if (ft_strlen(cur_lst->content) > i)
			i = ft_strlen(cur_lst->content);
		cur_lst = cur_lst->next;
	}
	data->width = i;
}

/*GNL the map into a list*/
static void	ft_map_to_lst(t_parser *parser)
{
	char	*gnl;

	parser->map_lst = ft_maplstnew(parser->last_gnl);
	gnl = get_next_line(parser->fd);
	while (gnl != NULL)
	{
		ft_maplstadd_back(&parser->map_lst, ft_maplstnew(gnl));
		gnl = get_next_line(parser->fd);
	}
}

/*Build the map in a 2D array*/
bool	ft_parser_map(t_apin *data, t_parser *parser)
{
	ft_map_to_lst(parser);
	ft_map_get_width_height(data, parser);
	ft_map_build(data, parser);
	if (ft_get_player_ori(data) == false)
		return (false);
	if (ft_map_illegal_char(data) == false)
		return (false);
	if (ft_map_is_closed(data) == false)
		return (ft_perror("map not closed"), false);
	ft_get_player_pos(data);
	return (true);
}
