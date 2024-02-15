/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:11:56 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/15 01:32:25 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_dir(t_apin *data)
{
	int	posneg1;
	int	posneg2;

	posneg1 = 1;
	posneg2 = 1;
	if (data->start_orientation == n || data->start_orientation == w)
		posneg1 = -1;
	else if (data->start_orientation == s)
		posneg2 = -1;
	if (data->start_orientation == n || data->start_orientation == s)
	{
		data->player.dirx = 0;
		data->player.diry = 1 * posneg1;
		data->player.planex = 0.66 * posneg2;
		data->player.planey = 0;
	}
	else if (data->start_orientation == e || data->start_orientation == w)
	{
		data->player.dirx = 1 * posneg1;
		data->player.diry = 0;
		data->player.planex = 0;
		data->player.planey = 0.66 * posneg1;
	}
}

void	init_ray(t_apin *data, int x)
{
	ft_bzero(&data->ray, sizeof(t_ray));// ? syntax ?
	data->ray.camerax = 2 * x / (double)WIDTH - 1;
	data->ray.dirx = data->player.dirx + data->player.planex * data->ray.camerax;
	data->ray.diry = data->player.dirx + data->player.planey * data->ray.camerax;
	data->ray.mapx = (int)data->player.posx;
	data->ray.mapy = (int)data->player.posy;
	data->ray.deltax = fabs(1 / data->ray.dirx);
	data->ray.deltay = fabs(1 / data->ray.diry);
}
