/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:28:30 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/10 20:41:46 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->add + (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

static void	set_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->add + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	set_fc(t_apin *data, int x)
{
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		if (y <= HEIGHT / 2)
			set_pixel(data->img, x, y, data->top);
		else
			set_pixel(data->img, x, y, data->bottom);
		y++;
	}
}

static t_img	*get_wall(t_apin *data)
{
	if (data->ray.side && data->ray.stepy < 0)
		return (data->i_wall_n);
	if (data->ray.side && data->ray.stepy > 0)
		return (data->i_wall_s);
	if (!data->ray.side && data->ray.stepx < 0)
		return (data->i_wall_w);
	if (!data->ray.side && data->ray.stepx > 0)
		return (data->i_wall_e);
	return (data->i_wall_n);
}

void	set_column(t_apin *data, int x)
{
	int		y;
	double	step;
	double	y_texture;
	t_img	*texture;

	texture = get_wall(data);
	set_fc(data, x);
	y_texture = 0;
	step = (double)((double)texture->height
			/ (double)(data->ray.end - data->ray.start));
	if (data->ray.start < 0)
		y_texture = step * data->ray.start * -1;
	if (data->ray.start < 0)
		data->ray.start = 0;
	y = data->ray.start;
	while (y <= data->ray.end)
	{
		if (y >= HEIGHT - 1)
			break ;
		set_pixel(data->img, x, y,
			get_pixel(texture, data->ray.wall_x * texture->width, y_texture));
		y++;
		y_texture += step;
	}
}
