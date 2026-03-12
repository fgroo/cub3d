/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:50 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/11 18:30:11 by rtwobie          ###   ########.fr       */
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

void	draw_map(t_mapdata *map, mlx_image_t *img, double scale);
void	draw_player(t_mapdata *map, mlx_image_t *img, double scale);
// void	draw_rays(mlx_image_t *map);
void	render_map(void *param);
int		init_images(t_data *data);

#endif
