/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:22 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/17 14:14:33 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define GAME_WIDTH 960
# define BLACK_BORDER_WIDTH 160

# include "MLX42.h"

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_raycast
{
	t_vector	hit;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		hit_dist;
	double		*arraycaster;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
}			t_raycast;
/*
 * Texture files are saved in char *tex[] in this exact order:
 * char *tex[4] = { ./path-of-north-tex, ./path-of-south-tex,
 *					./path-of-west-tex, ./path-of-east-tex }
 */
typedef struct s_mapdata
{
	char		*tex[4];
	int			floor_color;
	int			ceiling_color;
	int			height;
	int			width;
	char		spawn_orientation;
	t_vector	spawn_coordinates;
	t_vector	player_pos;
	t_vector	player_view;
	t_vector	cam_plane;
	double		rotspeed;
	char		**map;
}	t_mapdata;

typedef struct s_image
{
	mlx_image_t	*map_buf;
	mlx_image_t	*map;
}	t_image;

typedef struct s_data
{
	mlx_t		*mlx;
	t_mapdata	*map;
	t_image		*img;
	t_raycast	*raycast;
}	t_data;

void	key_hook(mlx_key_data_t keycode, void *data);

#endif // !CUB3D_H
