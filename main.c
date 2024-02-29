/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/29 22:49:49 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_apin data;

	ft_bzero(&data, sizeof(t_apin));
	if(ft_parser(ac, av, &data) == false)
		return(1);
	t_player	p;
	(void)p;


	data.mlx.mlx = mlx_init();
	init_player_dir();
	play_mlx();
	return (0);
}

play_mlx()
{
	t_img t;

	window = new window
	img = new img //void*
	t.add = mlx_get_data_addr //char*
	t.win
	t.height
	data.img = t
	
	init_texture
	
}