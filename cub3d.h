/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:24:46 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/09 19:01:41 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "./libft/includes/libft.h"

typedef char* t_path;
typedef int  t_color;
typedef char** t_map;
typedef struct s_pos{
	int	x;
	int y;
} t_pos;

enum e_orientation{
	
	undefined,
	n,
	s,
	e,
	w
};

typedef struct s_img
{
	void	*img;
}	t_img;

typedef struct s_apin{

// INITIAL SETTINGS
t_path	p_wall_n;
t_path	p_wall_s;
t_path	p_wall_e;
t_path	p_wall_w;

t_img	i_wall_n;
t_img	i_wall_s;
t_img	i_wall_e;
t_img	i_wall_w;

t_color	bottom;
t_color	top;

t_map	map; // each line end with \0, void is whitespace
size_t	height;
size_t	width;

int	start_orientation; //use enum e_orientation



// 
} t_apin;

#endif