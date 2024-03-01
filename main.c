/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/01 18:33:56 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_apin *data)
{
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	
}

play_mlx(t_apin *data)
{
	t_img temp;

	temp.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "!cub3d");
	temp.add = mlx_get_data_addr(&temp.img, &temp.bpp, &temp.line_len, &temp.line_num);
	temp.width = WIDTH;
	temp.height = HEIGHT;
	data->img = &temp;
	mlx_loop_hook(data->mlx, &game_loop, data);
	//init_texture
}

int	main(int ac, char **av)
{
	t_apin data;

	ft_bzero(&data, sizeof(t_apin));
	if(ft_parser(ac, av, &data) == false)
		return(1);
	t_player	p;
	(void)p;


	data.mlx = mlx_init();
	init_player_dir();
	play_mlx(&data);
	return (0);
}
