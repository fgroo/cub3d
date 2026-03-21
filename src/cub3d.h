/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:22 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/21 22:24:53 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 320
# define WINDOW_HEIGHT 240
# define GAME_WIDTH 480
# define GAME_HEIGHT 240
# define MAP_PXL_SIZE 320
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ROT_SPEED 0.15
# define FOV 2.66
# define DETAIL_LEVEL 1

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
	char		hit_side;
	t_vector	ray_dir;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
}			t_raycast;

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
	mlx_image_t	*game_upscld;
}	t_image;

typedef struct s_textures
{
	mlx_texture_t	*north_wall;
	mlx_texture_t	*south_wall;
	mlx_texture_t	*east_wall;
	mlx_texture_t	*west_wall;
}	t_textures;

typedef struct s_data
{
	mlx_t		*mlx;
	t_mapdata	*map;
	t_image		*img;
	t_raycast	*raycast;
	t_textures	*textures;
	size_t		ray_count;
	uint32_t	game_width;
	uint32_t	game_height;
	int32_t		window_width;
	int32_t		window_height;
}	t_data;

void		init_values(t_mapdata *mapdata);
int			init_data(t_data *data);

#endif
