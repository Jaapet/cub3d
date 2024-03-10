/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:11:15 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/10 20:35:24 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	dda(t_apin *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.distx < data->ray.disty)
		{
			data->ray.distx += data->ray.deltax;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.disty += data->ray.deltay;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
}

static void	get_height(t_apin *data)
{
	int	height;

	if (data->ray.side == 0)
		data->ray.perpdist = data->ray.distx - data->ray.deltax;
	else
		data->ray.perpdist = data->ray.disty - data->ray.deltay;
	if (data->ray.side)
		data->ray.wall_x = data->player.posx
			+ data->ray.perpdist * data->ray.dirx;
	else
		data->ray.wall_x = data->player.posy
			+ data->ray.perpdist * data->ray.diry;
	data->ray.wall_x -= floor(data->ray.wall_x);
	height = (int)(HEIGHT / data->ray.perpdist);
	data->ray.start = HEIGHT / 2 - height / 2;
	data->ray.end = HEIGHT / 2 + height / 2;
}

void	raycasting(t_apin *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, x);
		init_dda(data);
		dda(data);
		get_height(data);
		set_column(data, x);
		x++;
	}
}
