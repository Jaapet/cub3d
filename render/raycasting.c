/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:11:15 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/01 18:54:06 by ndesprez         ###   ########.fr       */
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
			data->ray.mapx += data->ray.stepx;
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
		data->ray.perpdist = data->ray.disty - data->ray.deltax;
	height = (int)(HEIGHT / data->ray.perpdist);
	data->ray.start = height / 2 * -1 + HEIGHT / 2;
	data->ray.end = height / 2 + HEIGHT / 2;
	if (data->ray.start < 0)
		data->ray.start = 0;
	if (data->ray.end >= HEIGHT)
		data->ray.end = HEIGHT - 1;
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->add + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	set_column(t_apin *data, int x)
{
	int	i;

	i = data->ray.start;
	while (i <= data->ray.end)
	{
		set_pixel(data->img, x, i, 66);
		i++;
	}
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
