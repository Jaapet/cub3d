/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:31:22 by ndesprez          #+#    #+#             */
/*   Updated: 2024/03/10 21:07:04 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_forward(t_apin *data)
{
	if (data->map[(int)floor(data->player.posy)]
		[(int)floor(data->player.posx + data->player.dirx * MOVESPEED)] == '0')
		data->player.posx += data->player.dirx * MOVESPEED;
	if (data->map[(int)floor(data->player.posy + data->player.diry * MOVESPEED)]
		[(int)floor(data->player.posx)] == '0')
		data->player.posy += data->player.diry * MOVESPEED;
}

static void	move_left(t_apin *data)
{
	if (data->map[(int)floor(data->player.posy)]
		[(int)floor(data->player.posx + data->player.diry * MOVESPEED)] == '0')
		data->player.posx += data->player.diry * MOVESPEED;
	if (data->map[(int)floor(data->player.posy - data->player.dirx * MOVESPEED)]
		[(int)floor(data->player.posx)] == '0')
		data->player.posy -= data->player.dirx * MOVESPEED;
}

static void	move_backward(t_apin *data)
{
	if (data->map[(int)floor(data->player.posy)]
		[(int)floor(data->player.posx - data->player.dirx * MOVESPEED)] == '0')
		data->player.posx -= data->player.dirx * MOVESPEED;
	if (data->map[(int)floor(data->player.posy - data->player.diry * MOVESPEED)]
		[(int)floor(data->player.posx)] == '0')
		data->player.posy -= data->player.diry * MOVESPEED;
}

static void	move_right(t_apin *data)
{
	if (data->map[(int)floor(data->player.posy)]
		[(int)floor(data->player.posx - data->player.diry * MOVESPEED)] == '0')
		data->player.posx -= data->player.diry * MOVESPEED;
	if (data->map[(int)floor(data->player.posy + data->player.dirx * MOVESPEED)]
		[(int)floor(data->player.posx)] == '0')
		data->player.posy += data->player.dirx * MOVESPEED;
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
		move_right(data);
	if (data->keys[4])
		rotl(data);
	if (data->keys[5])
		rotr(data);
}
