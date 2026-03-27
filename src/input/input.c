/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:25:10 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/21 01:15:08 by fgroo            ###   ########.fr       */
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
void	move_player(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		moving(data, 'W');
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		moving(data, 'A');
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		moving(data, 'S');
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		moving(data, 'D');
}

void	rotate_player(t_data *data)
{
	double	delta_time;

	delta_time = data->mlx->delta_time;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		matrix_rotation(&data->map->cam_plane.x,
			&data->map->cam_plane.y, -ROT_SPEED * delta_time);
		matrix_rotation(&data->map->player_view.x,
			&data->map->player_view.y, -ROT_SPEED * delta_time);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		matrix_rotation(&data->map->cam_plane.x,
			&data->map->cam_plane.y, ROT_SPEED * delta_time);
		matrix_rotation(&data->map->player_view.x,
			&data->map->player_view.y, ROT_SPEED * delta_time);
	}
}

void	input_hook(void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	move_player(data);
	rotate_player(data);
}
