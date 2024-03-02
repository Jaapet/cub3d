/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:01 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/27 17:07:13 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_apin data;

	ft_bzero(&data, sizeof(t_apin));
	if(ft_parser(ac, av, &data) == false)
		exit(1);
	t_player	p;
	(void)p;
	exit(0);
	return (0);
}