/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:25:10 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/08 00:19:54 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "rotate.h"
#include "error.h"
#include "cleanup.h"

#include <stdio.h>
#include <stdlib.h>

void	key_hook(mlx_key_data_t keycode, void *param)
{
	mlx_image_t	*img;
	t_data		*data;
	int32_t		xy[2];

	data = (t_data *)param;
	img = mlx_new_image(data->mlx, 256, 256);
	if (!img || (mlx_image_to_window(data->mlx, img, 0, 0) < 0))
		pr_error("error: mlx_image\n");
	if (keycode.key == MLX_KEY_ESCAPE && (mlx_delete_image(data->mlx, img), 1))
		(free(0), mlx_terminate(data->mlx), free_mapdata(data->map), exit(0));
	else if (keycode.key == MLX_KEY_W)
		(free(0),printf("Keypress: W\n"), moving(data->map, 'W'));
	else if (keycode.key == MLX_KEY_A)
		(free(0),printf("Keypress: A\n"), moving(data->map, 'A'));
	else if (keycode.key == MLX_KEY_S)
		(free(0),printf("Keypress: S\n"), moving(data->map, 'S'));
	else if (keycode.key == MLX_KEY_D)
		(free(0),printf("Keypress: D\n"), moving(data->map, 'D'));
	else if (keycode.key == MLX_KEY_LEFT)
		(free(0),printf("Keypress: LEFT\n"), matrix_rotation(&data->map->cam_plane.x, &data->map->cam_plane.y, 0.02), matrix_rotation(&data->map->player_view.x, &data->map->player_view.y, -0.02));
	else if (keycode.key == MLX_KEY_RIGHT)
		(free(0), printf("Keypress: RIGHT\n"), matrix_rotation(&data->map->cam_plane.x, &data->map->cam_plane.y, -0.02), matrix_rotation(&data->map->player_view.x, &data->map->player_view.y, 0.02));
	xy[0] = (int32_t)data->map->player_pos.x;
	xy[1] = (int32_t)data->map->player_pos.y;
	put_point(img, (t_vertex2i){xy[0], xy[1]}, 5, 0xFF0000FF);
}
