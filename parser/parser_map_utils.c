/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:36:37 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/11 14:58:33 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static bool	ft_is_player_floor_wall(char c)
{
	if (c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == '0' || c == '1')
		return (true);
	return (false);
}

void	ft_get_player_pos(t_apin *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (ft_is_player(data->map[j][i]))
			{
				data->player.posx = i + 0.5;
				data->player.posy = j + 0.5;
				data->map[j][i] = '0';
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

bool	ft_map_illegal_char(t_apin *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (!(ft_is_player_floor_wall(data->map[j][i])
				|| data->map[j][i] == ' '))
				return (ft_perror("illegal char on the map"), false);
			i++;
		}
		i = 0;
		j++;
	}
	return (true);
}

bool	ft_map_is_closed(t_apin *data)
{
	size_t	i[2];

	ft_bzero(i, sizeof(size_t) * 2);
	while (data->map[i[1]])
	{
		while (data->map[i[1]][i[0]])
		{
			if (ft_is_player(data->map[i[1]][i[0]])
				|| data->map[i[1]][i[0]] == '0')
			{
				if (ft_is_player_floor_wall(data->map[i[1]][i[0] - 1]) == false)
					return (false);
				if (ft_is_player_floor_wall(data->map[i[1]][i[0] + 1]) == false)
					return (false);
				if (ft_is_player_floor_wall(data->map[i[1] - 1][i[0]]) == false)
					return (false);
				if (ft_is_player_floor_wall(data->map[i[1] + 1][i[0]]) == false)
					return (false);
			}
			i[0]++;
		}
		i[0] = 0;
		i[1]++;
	}
	return (true);
}
