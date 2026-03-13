/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:50 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/13 21:48:22 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

# include <stdint.h>

# define WALLTILE_COLOR 0xFFFFFFFF
# define FLOORTILE_COLOR 0x000000FF
# define PLAYER_COLOR 0xFF0000FF
# define TILESIZE 8
# define PLAYERSIZE 2
# define SCALE 4
# define RAY_COUNT 20

void		draw_map(t_mapdata *map, mlx_image_t *img, double scale);
void		draw_player(t_mapdata *map, mlx_image_t *img, double scale);
double		get_map_scale(t_mapdata *map, mlx_image_t *img);
void		dda(t_vector start, t_vector end, mlx_image_t *img);
void		draw_rays(t_data *data);
void		render_map(void *param);
int			init_images(t_data *data);
t_vector	raycast_wall_hit(t_mapdata *map, t_raycast *ray, t_vector dir);
int			is_wall(t_mapdata *map, int x, int y);

#endif
