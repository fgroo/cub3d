/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/21 23:13:03 by fgroo            ###   ########.fr       */
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

bool	is_correct_size(mlx_texture_t *texture)
{
	return (texture->width == TEXTURE_WIDTH
		&& texture->height == TEXTURE_HEIGHT);
}

int	load_textures(t_data *data, t_textures *textures)
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
		return (1);
	if (load_textures(data, data->textures) == 1)
		return (pr_error("loading textures\n"), 1);
	mlx_loop_hook(data->mlx, render_map, data);
	mlx_loop_hook(data->mlx, render_game, data);
	mlx_loop_hook(data->mlx, input_hook, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
		return (pr_error("Please enter a .cub file\n"), 1);
	ft_memset(&data, 0, sizeof(data));
	if (init_data(&data))
		return (cleanup(&data), 1);
	if (parser(data.map, argv[1]))
		return (cleanup(&data), 1);
	init_values(data.map);
	if (init_mlx(&data))
		return (cleanup(&data), 1);
	cleanup(&data);
	return (0);
}
