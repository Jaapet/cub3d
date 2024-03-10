/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:02:37 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/10 20:40:34 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotl(t_apin *data)
{
	double	temp;

	temp = data->player.dirx;
	data->player.dirx = data->player.dirx * cos(-ROTSPEED / 2)
		- data->player.diry * sin(-ROTSPEED / 2);
	data->player.diry = temp * sin(-ROTSPEED / 2)
		+ data->player.diry * cos(-ROTSPEED / 2);
	temp = data->player.planex;
	data->player.planex = data->player.planex * cos(-ROTSPEED / 2)
		- data->player.planey * sin(-ROTSPEED / 2);
	data->player.planey = temp * sin(-ROTSPEED / 2)
		+ data->player.planey * cos(-ROTSPEED / 2);
}

void	rotr(t_apin *data)
{
	double	temp;

	temp = data->player.dirx;
	data->player.dirx = data->player.dirx * cos(ROTSPEED / 2)
		- data->player.diry * sin(ROTSPEED / 2);
	data->player.diry = temp * sin(ROTSPEED / 2)
		+ data->player.diry * cos(ROTSPEED / 2);
	temp = data->player.planex;
	data->player.planex = data->player.planex * cos(ROTSPEED / 2)
		- data->player.planey * sin(ROTSPEED / 2);
	data->player.planey = temp * sin(ROTSPEED / 2)
		+ data->player.planey * cos(ROTSPEED / 2);
}
