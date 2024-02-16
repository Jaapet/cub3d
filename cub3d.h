/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:24:46 by ggualerz          #+#    #+#             */
/*   Updated: 2024/02/16 15:07:18 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "./mlx/mlx.h"
# include "./libft/includes/libft.h"

# define WIDTH 640
# define HEIGHT 480

typedef char* t_path;
typedef int  t_color;
typedef char** t_map;
typedef struct s_pos{
	int	x;
	int y;
} t_pos;

typedef struct s_img
{
	void	*img;
}	t_img;

typedef struct s_ray
{
	/*----x coordinate on the camera plane----*/
	double	camerax;

	/*----ray direction----*/
	double	dirx;
	double	diry;

	/*----map box coordinates----*/
	int		mapx;
	int		mapy;

	/*----distance from pos----*/
	double	distx;
	double	disty;

	/*----perpendicular dist----*/
	double	perpdist;

	/*----delta steps----*/
	double	deltax;
	double	deltay;

	/*----direction to step----*/
	int		stepx;
	int		stepy;

	/*----wall hit----*/
	bool	hit;//wall hit
	bool	side;//NS = true, EW = false;

	/*----draw info----*/
	int		start;
	int		end;
}	t_ray;

typedef struct s_player
{
	/*----position of the player----*/
	double	posx;
	double	posy;

	/*----initial direction of the player----*/
	double	dirx;
	double	diry;

	/*----vector of the camera plane----*/
	double	planex;
	double	planey;
}	t_player;

typedef struct s_apin
{
// INITIAL SETTINGS
	t_path		p_wall_n;
	t_path		p_wall_s;
	t_path		p_wall_e;
	t_path		p_wall_w;

	t_img		i_wall_n;
	t_img		i_wall_s;
	t_img		i_wall_e;
	t_img		i_wall_w;

	t_color		bottom;
	t_color		top;

	t_map		map; // each line end with \0, void char are whitespace
  size_t	height;
  size_t	width;

  char	start_ori; //N S E W
	t_player	player;
	t_ray		ray;

	char		start_orientation;

}	t_apin;

/*----RAYCASTING----*/
void	init_ray(t_apin *data, int x);
void	init_dda(t_apin *data);

# include "./parser/parser.h"
//PARSER
bool ft_parser(int ac, char **av, t_apin *data);

#endif