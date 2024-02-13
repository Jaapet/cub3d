/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/13 18:06:29 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		i;

	(void)av;
	(void)ac;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "test");
	while (1)
	{
		i = 0;
		i++;
	}
	(void)win;
	return (0);
}