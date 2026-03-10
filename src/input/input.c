/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:25:10 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/10 15:05:14 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include "cub3d.h"
#include "cleanup.h"

#include "render.h" //delete later
#include <math.h> //delte later

#include <stdio.h>
#include <stdlib.h>

// TODO: smoother movement as soon as a button is held down
void	move_player(t_mapdata *map, double delta_time,
	const mlx_key_data_t *keycode)
{
	if (keycode->key == MLX_KEY_W)
		moving(map, delta_time, 'W');
	else if (keycode->key == MLX_KEY_A)
		moving(map, delta_time, 'A');
	else if (keycode->key == MLX_KEY_S)
		moving(map, delta_time, 'S');
	else if (keycode->key == MLX_KEY_D)
		moving(map, delta_time, 'D');
}

void	rotate_player(t_mapdata *map, double delta_t,
	 const mlx_key_data_t *keycode)
{
	if (keycode->key == MLX_KEY_LEFT)
	{
		matrix_rotation(&map->cam_plane.x, &map->cam_plane.y,
			ROT_SPEED, delta_t);
		matrix_rotation(&map->player_view.x, &map->player_view.y,
			-ROT_SPEED, delta_t);
	}
	else if (keycode->key == MLX_KEY_RIGHT)
	{
		matrix_rotation(&map->cam_plane.x, &map->cam_plane.y,
			-ROT_SPEED, delta_t);
		matrix_rotation(&map->player_view.x, &map->player_view.y,
			ROT_SPEED, delta_t);
	}
}

void	key_hook(mlx_key_data_t keycode, void *param)
{
	t_data		*data;
	t_mapdata	*map;

	data = (t_data *)param;
	map = data->map;
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		cleanup(data);
		mlx_terminate(data->mlx);
		exit(0);
	}
	else if (keycode.key == MLX_KEY_W
		|| keycode.key == MLX_KEY_A
		|| keycode.key == MLX_KEY_S
		|| keycode.key == MLX_KEY_D)
		move_player(map, data->mlx->delta_time,&keycode);
	else if (keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_RIGHT)
		rotate_player(map, data->mlx->delta_time, &keycode);
	printf("player x: %d\n", (int)round(map->player_pos.x * TILESIZE * SCALE));
	printf("player y: %d\n", (int)round(map->player_pos.y * TILESIZE * SCALE));
	printf("player x: %f\n", map->player_pos.x);
	printf("player y: %f\n", map->player_pos.y);
}
