/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/19 22:03:40 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "MLX42.h"
#include "cleanup.h"
#include "error.h"
#include "input.h"
#include "libft.h"
#include "parser.h"
#include "render.h"

#include <stddef.h>

bool	is_correct_size(mlx_texture_t *texture)
{
	return (texture->width == TEXTURE_WIDTH
		&& texture->height == TEXTURE_HEIGHT);
}

int load_textures(t_data *data, t_textures *textures)
{
	textures->north_wall = mlx_load_png(data->map->tex[0]);
	if (!textures->north_wall)
		return (1);
	textures->south_wall = mlx_load_png(data->map->tex[1]);
	if (!textures->south_wall)
		return (1);
	textures->east_wall = mlx_load_png(data->map->tex[2]);
	if (!textures->east_wall)
		return (1);
	textures->west_wall = mlx_load_png(data->map->tex[3]);
	if (!textures->west_wall)
		return (1);
	if (!is_correct_size(textures->north_wall)
		|| !is_correct_size(textures->south_wall)
		|| !is_correct_size(textures->east_wall)
		|| !is_correct_size(textures->west_wall))
		return (1);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_get_monitor_size(0, &data->window_width, &data->window_height);
	mlx_set_window_size(data->mlx, data->window_width, data->window_height);
	if (init_images(data))
	{
		cleanup(data);
		return (1);
	}
	if (load_textures(data, data->textures) == 1)
		return (pr_error("loading textures\n"), cleanup(data), 1);
	mlx_loop_hook(data->mlx, render_map, data);
	mlx_loop_hook(data->mlx, render_game, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx); // NOTE: is there a function to break the loop?
	mlx_terminate(data->mlx);
	return (0);
}

uint32_t adjust(uint32_t resolution)
{
	if (resolution % 8 == 0)
		return (resolution);
	else if (resolution % 8 >= 4)
		return (resolution + resolution % 8);
	return (resolution - resolution % 8);
}

int	init_data(t_data *data)
{
	const uint32_t	detail_level = 4;

	data->game_width = adjust(GAME_WIDTH);
	data->game_height = adjust(GAME_HEIGHT);
	data->map = ft_calloc(1, sizeof(*data->map));
	if (!data->map)
		return (pr_error("malloc\n"), cleanup(data), 1);
	data->img = ft_calloc(1, sizeof(*data->img));
	if (!data->img)
		return (pr_error("malloc\n"), cleanup(data), 1);
	data->ray_count = data->game_width / detail_level;
	data->raycast = ft_calloc(data->ray_count, sizeof(*data->raycast));
	if (!data->raycast)
		return (pr_error("malloc\n"), cleanup(data), 1);
	data->textures = ft_calloc(1, sizeof(*data->textures));
	if (!data->textures)
		return (pr_error("malloc\n"), cleanup(data), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
		return (pr_error("Please enter a .cub file\n"), 1);
	ft_memset(&data, 0, sizeof(data));
	if (init_data(&data))
		return (1);
	if (parser(data.map, argv[1]))
		return (1);
	init_values(data.map);
	if (init_mlx(&data))
		return (1);
	return (0);
}
