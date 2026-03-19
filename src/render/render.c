/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 21:35:32 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "input.h"
#include "debug.h"

#include "MLX42.h"
#include "cub3d.h"

double	get_map_scale(t_mapdata *map, mlx_image_t *img)
{
	if (map->width > map->height)
		return ((double)img->width / ((double)map->width * TILESIZE));
	return ((double)img->height / ((double)map->height * TILESIZE));
}

// NOTE: This function will be called each frame
void	render_map(void *param)
{
	t_data		*data;
	mlx_image_t	*tmp;

	data = (t_data *)param;
	draw_map_img(data->map, data->img->map_buf);
	draw_rays(data);
	tmp = data->img->map;
	data->img->map = data->img->map_buf;
	data->img->map_buf = tmp;
}

// NOTE: This function will be called each frame
void	render_game(void *param)
{
	t_data		*data;
	mlx_image_t	*tmp;

	data = (t_data *)param;
	draw_game_img(data, data->img->game_buf);
	tmp = data->img->game;
	data->img->game = data->img->game_buf;
	data->img->game_buf = tmp;
	upscale(data);
	display_debug(data);
}

// TODO: change values of width and height later
// TEST: Check if it is safe to call delete on NULL pointers!
int	init_images(t_data *data)
{
	data->img->map = mlx_new_image(data->mlx, MAP_PXL_SIZE, MAP_PXL_SIZE);
	data->img->map_buf = mlx_new_image(data->mlx, MAP_PXL_SIZE, MAP_PXL_SIZE);
	data->img->game = mlx_new_image(data->mlx, data->game_width,
			data->game_height);
	data->img->game_buf = mlx_new_image(data->mlx, data->game_width,
			data->game_height);
	data->img->game_upscld = mlx_new_image(data->mlx,
			(uint32_t)data->window_width, (uint32_t)data->window_height);
	if (!data->img->map || !data->img->map_buf || !data->img->game_upscld
		|| !data->img->game || !data->img->game_buf)
	{
		mlx_delete_image(data->mlx, data->img->map);
		mlx_delete_image(data->mlx, data->img->map_buf);
		mlx_delete_image(data->mlx, data->img->game);
		mlx_delete_image(data->mlx, data->img->game_buf);
		mlx_delete_image(data->mlx, data->img->game_upscld);
		return (1);
	}
	mlx_image_to_window(data->mlx, data->img->game_upscld, 0, 0);
	mlx_image_to_window(data->mlx, data->img->map, 0, 0);
	return (0);
}
