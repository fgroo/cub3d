/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:58 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/13 22:02:13 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

#include <math.h>

void	draw_player(t_mapdata *map, mlx_image_t *img, double scale)
{
	t_vertex2i	pos;
	t_vertex2i	orientation;
	int			player_size;

	player_size = clamp((int)(PLAYERSIZE * scale), 1, TILESIZE);
	pos.x = (int)round((map->player_pos.x) * TILESIZE * scale);
	pos.y = (int)round((map->player_pos.y) * TILESIZE * scale);
	put_point(img, pos, player_size, PLAYER_COLOR);
	orientation.x = \
		(int)round((map->player_pos.x + map->player_view.x) * TILESIZE * scale);
	orientation.y = \
		(int)round((map->player_pos.y + map->player_view.y) * TILESIZE * scale);
	put_line(img, pos, orientation, PLAYER_COLOR);
}
