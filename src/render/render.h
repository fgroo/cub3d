/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:50 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/20 11:58:53 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

# include <stdint.h>

typedef struct s_upscale
{
	uint32_t	*s;
	uint32_t	*d;
	uint32_t	x;
	uint32_t	y;
	float		wstep;
	float		hstep;
}				t_upscale;

# define WALLTILE_COLOR  0xFFFFFFFF
# define FLOORTILE_COLOR 0x000000FF
# define PLAYER_COLOR    0xFF0000FF
# define RGB_GREEN       0x228B22FF
# define RGB_GREEN_DIM   0x114511FF
# define RGB_GREY        0x808080FF
# define RGB_GREY_DIM    0x404040FF
# define RGB_MAGENTA     0xFFFF00FF
# define TILESIZE        8
# define PLAYERSIZE      2
# define SCALE           4

void		draw_map(t_mapdata *map, mlx_image_t *img, double scale);
void		draw_game_img(t_data *data, mlx_image_t *img);
void		draw_map_img(t_mapdata *map, mlx_image_t *img);
void		draw_player(t_mapdata *map, mlx_image_t *img, double scale);
void		draw_walls_textured(t_data *data, mlx_image_t *img);
double		get_map_scale(t_mapdata *map, mlx_image_t *img);
void		dda(t_vector start, t_vector end, mlx_image_t *img);
void		draw_rays(t_data *data);
void		render_map(void *param);
void		render_game(void *param);
int			init_images(t_data *data);
void		upscale(t_data *data);

#endif
