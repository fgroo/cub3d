/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:22 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/18 12:28:59 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 960 
# define WINDOW_HEIGHT 360
# define GAME_WIDTH 640

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
	int			hit_side_x;
	int			hit_side_y;
	double		*rays;
	size_t		ray_count;
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
	uint32_t	floor_color;
	uint32_t	ceiling_color;
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
	mlx_image_t	*game_buf;
	mlx_image_t	*game;
}	t_image;

typedef struct s_data
{
	mlx_t		*mlx;
	t_mapdata	*map;
	t_image		*img;
	t_raycast	*raycast;
	uint32_t	game_width;
	uint32_t	game_height;
}	t_data;

#endif // !CUB3D_H
