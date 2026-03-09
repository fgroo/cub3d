/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:58 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/09 18:16:58 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

#include <math.h>
#include <stdio.h>

void	render_player(void *param)
{
	t_data		*data;
	t_vertex2i	p1;
	t_vertex2i	p2;

	data = (t_data *)param;
	p1.x = 0;
	p1.y = 0;
	p2.x = (int)data->img->player->width - 1;
	p2.y = (int)data->img->player->height - 1;
	put_square(data->img->player, p1, p2, PLAYER_COLOR);
	mlx_image_to_window(data->mlx, data->img->player,
		(int)round(data->map->spawn_coordinates.x) * TILESIZE * SCALE,
		(int)round(data->map->spawn_coordinates.y) * TILESIZE * SCALE);
}

void	render_player_pos(void *param)
{
	t_data		*data;
	mlx_image_t	*player;
	t_mapdata	*map;

	data = (t_data *)param;
	player = data->img->player;
	map = data->map;
	player->instances->x = (int)round(map->player_pos.x * TILESIZE * SCALE);
	player->instances->y = (int)round(map->player_pos.y * TILESIZE * SCALE);
}

/* NOTE:
 * There should be two methods for displaying player movement:
 * Method 1:
 *		- Player image is the same size as the map
 *		- On every frame put_point() to player position and turn off the pixels
 *		  of the previous position
 * Method 2:
 *		- Player image is exactly the size of put_point()
 *		- On every frame update the image position on the window
 */
