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
	void		render_map(void *param);
int			init_images(t_data *data);

#endif
