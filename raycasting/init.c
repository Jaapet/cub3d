/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:11:56 by ndesprez          #+#    #+#             */
/*   Updated: 2024/02/15 16:51:00 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_dir(t_apin *data)
{
	int	posneg1;
	int	posneg2;

	posneg1 = 1;
	posneg2 = 1;
	if (data->start_orientation == 'N' || data->start_orientation == 'W')
		posneg1 = -1;
	else if (data->start_orientation == 'S')
		posneg2 = -1;
	if (data->start_orientation == 'N' || data->start_orientation == 'S')
	{
		data->player.dirx = 0;
		data->player.diry = 1 * posneg1;
		data->player.planex = 0.66 * posneg2;
		data->player.planey = 0;
	}
	else if (data->start_orientation == 'E' || data->start_orientation == 'W')
	{
		data->player.dirx = 1 * posneg1;
		data->player.diry = 0;
		data->player.planex = 0;
		data->player.planey = 0.66 * posneg1;
	}
}

void	init_ray(t_apin *data, int x)
{
	ft_bzero(&data->ray, sizeof(t_ray));
	data->ray.camerax = 2 * x / (double)WIDTH - 1;
	data->ray.dirx = data->player.dirx + data->player.planex * data->ray.camerax;
	data->ray.diry = data->player.dirx + data->player.planey * data->ray.camerax;
	data->ray.mapx = (int)data->player.posx;
	data->ray.mapy = (int)data->player.posy;
	data->ray.deltax = fabs(1 / data->ray.dirx);
	data->ray.deltay = fabs(1 / data->ray.diry);
}

void	init_dda(t_apin *data)
{
	if (data->ray.dirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.distx = (data->player.posx - data->ray.mapx) * data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.distx = (data->ray.mapx + 1 - data->player.posx) * data->ray.deltax;
	}
	if (data->ray.diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.disty = (data->player.posy - data->ray.mapy) * data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.disty = (data->ray.mapy + 1 - data->player.posy) * data->ray.deltay;
	}
}
