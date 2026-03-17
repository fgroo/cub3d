/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/17 16:52:57 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "input.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"

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
}

// TODO: change values of width and height later
int	init_images(t_data *data)
{
	uint32_t	width;
	uint32_t	height;

	width = 320;
	height = width;
	data->img->map = mlx_new_image(data->mlx, width, height);
	data->img->map_buf = mlx_new_image(data->mlx, width, height);
	data->img->game = mlx_new_image(data->mlx, GAME_WIDTH, WINDOW_HEIGHT);
	data->img->game_buf = mlx_new_image(data->mlx, GAME_WIDTH, WINDOW_HEIGHT);
	if (!data->img->map || !data->img->map_buf
		|| !data->img->game || !data->img->game_buf)
	{
		mlx_delete_image(data->mlx, data->img->map);
		mlx_delete_image(data->mlx, data->img->map_buf);
		mlx_delete_image(data->mlx, data->img->game);
		mlx_delete_image(data->mlx, data->img->game_buf);
		return (1);
	}
	mlx_image_to_window(data->mlx, data->img->map, 0, 0);
	mlx_image_to_window(data->mlx, data->img->game, 
					 WINDOW_WIDTH - GAME_WIDTH, 0);
	return (0);
}
