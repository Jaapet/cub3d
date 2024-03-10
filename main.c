/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/03/10 21:03:21 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	main(int ac, char **av)
{
	t_apin	data;

	ft_bzero(&data, sizeof(t_apin));
	if (ft_parser(ac, av, &data) == false)
		exit(1);
	data.mlx = mlx_init();
	init_player_dir(&data);
	init_texture(&data);
	play_mlx(&data);
	exit(0);
	return (0);
}
