/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:22:02 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/07 16:26:30 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_apin *data)
{
	if (data->map[(int)(data->player.posx + (data->player.dirx / 30))][(int)data->player.posy] == '0')
		data->player.posx += data->player.dirx / 30;
	if (data->map[(int)data->player.posx][(int)(data->player.posy + (data->player.diry / 30))] == '0')
		data->player.posy += data->player.diry / 30;
}

void	move_left(t_apin *data)
{
	if (data->map[(int)(data->player.posx + (data->player.diry / 30))][(int)data->player.posy] == '0')
		data->player.posx += data->player.diry / 30;
	if (data->map[(int)data->player.posx][(int)(data->player.posy - (data->player.dirx / 30))] == '0')
		data->player.posy -= data->player.dirx / 30;
}

void	move_backward(t_apin *data)
{
	if (data->map[(int)(data->player.posx - (data->player.dirx / 30))][(int)data->player.posy] == '0')
		data->player.posx -= data->player.dirx / 30;
	if (data->map[(int)data->player.posx][(int)(data->player.posy - (data->player.diry / 30))] == '0')
		data->player.posy -= data->player.diry / 30;
}

void	move_right(t_apin *data)
{
	if (data->map[(int)(data->player.posx - (data->player.diry / 30))][(int)data->player.posy] == '0')
		data->player.posx -= data->player.diry / 30;
	if (data->map[(int)data->player.posx][(int)(data->player.posy + (data->player.dirx / 30))] == '0')
		data->player.posy += data->player.dirx / 30;
}

void	move(t_apin *data)
{
	if (data->keys[0])
		move_forward(data);
	if (data->keys[1])
		move_left(data);
	if (data->keys[2])
		move_backward(data);
	if (data->keys[3])
		move_right(data);/*
	if (data->keys[4])
		rotl(data);
	if (data->keys[5])
		rotr(data);*/
}
