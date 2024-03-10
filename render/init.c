/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:11:56 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/10 21:01:58 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_dir(t_apin *data)
{
	int	posneg1;
	int	posneg2;

	posneg1 = 1;
	posneg2 = 1;
	if (data->start_ori == 'N' || data->start_ori == 'W')
		posneg1 = -1;
	else if (data->start_ori == 'S')
		posneg2 = -1;
	if (data->start_ori == 'N' || data->start_ori == 'S')
	{
		data->player.dirx = 0;
		data->player.diry = 1 * posneg1;
		data->player.planex = 0.66 * posneg2;
		data->player.planey = 0;
	}
	else if (data->start_ori == 'E' || data->start_ori == 'W')
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
	data->ray.dirx = data->player.dirx
		+ data->player.planex * data->ray.camerax;
	data->ray.diry = data->player.diry
		+ data->player.planey * data->ray.camerax;
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
		data->ray.distx = (data->player.posx - data->ray.mapx)
			* data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.distx = (data->ray.mapx + 1.0 - data->player.posx)
			* data->ray.deltax;
	}
	if (data->ray.diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.disty = (data->player.posy - data->ray.mapy)
			* data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.disty = (data->ray.mapy + 1.0 - data->player.posy)
			* data->ray.deltay;
	}
}

static void	get_texture(t_apin *data, t_img *img, t_path path)
{
	img->img = mlx_xpm_file_to_image
		(data->mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_perror("Can't open image.");
	img->add = mlx_get_data_addr
		(img->img, &img->bpp, &img->line_len, &img->line_num);
}

void	init_texture(t_apin *data)
{
	data->i_wall_n = ft_calloc(1, sizeof(t_img));
	get_texture(data, data->i_wall_n, data->p_wall_n);
	data->i_wall_s = ft_calloc(1, sizeof(t_img));
	get_texture(data, data->i_wall_s, data->p_wall_s);
	data->i_wall_e = ft_calloc(1, sizeof(t_img));
	get_texture(data, data->i_wall_e, data->p_wall_e);
	data->i_wall_w = ft_calloc(1, sizeof(t_img));
	get_texture(data, data->i_wall_w, data->p_wall_w);
}
