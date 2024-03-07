/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/07 15:01:14 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_apin *data)
{
	raycasting(data);
	move(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	key_press(int key_num, t_apin *data)
{
	if (key_num == 65307)
		exit(0);
	if (key_num == 119)//w
		data->keys[0] = 1;
	if (key_num == 97)//a
		data->keys[1] = 1;
	if (key_num == 115)//s
		data->keys[2] = 1;
	if (key_num == 100)//d
		data->keys[3] = 1;
	if (key_num == 65361)//l
		data->keys[4] = 1;
	if (key_num == 65363)//r
		data->keys[5] = 1;
	(void)data;
	return (0);
}

int	key_release(int key_num, t_apin *data)
{
	if (key_num == 65307)
		exit(0);
	if (key_num == 119)
		data->keys[0] = 0;
	if (key_num == 97)
		data->keys[1] = 0;
	if (key_num == 115)
		data->keys[2] = 0;
	if (key_num == 100)
		data->keys[3] = 0;
	if (key_num == 65361)//l
		data->keys[4] = 0;
	if (key_num == 65363)//r
		data->keys[5] = 0;
	(void)data;
	return (0);
}
int ft_exit(void)
{
	exit(0);
}

void	play_mlx(t_apin *data)
{
	t_img temp;

	temp.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "!cub3d");
	temp.add = mlx_get_data_addr(temp.img, &temp.bpp, &temp.line_len, &temp.line_num);
	temp.width = WIDTH;
	temp.height = HEIGHT;
	data->img = &temp;
	mlx_loop_hook(data->mlx, &game_loop, data);
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	mlx_hook(data->win, 33, 1L << 17, &ft_exit, NULL);
	mlx_loop(data->mlx);

}

void	get_texture(t_apin *data, t_img *img, t_path path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (!img->img)
	{
		printf("%s\n", path);
		//ft_error("Error :\n\033[41mCan't open some ressources\033[0m\n");
	}
	img->add = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->line_num);
}

void	init_texture(t_apin *data)
{
	data->i_wall_n = ft_calloc(1, sizeof(t_img));
	get_texture(data, data->i_wall_n, data->p_wall_n);
}

int	main(int ac, char **av)
{
	t_apin data;

	ft_bzero(&data, sizeof(t_apin));
	if(ft_parser(ac, av, &data) == false)
		exit(1);
	data.mlx = mlx_init();
	init_player_dir(&data);
	init_texture(&data);
	play_mlx(&data);
	exit(0);
	return (0);
}
