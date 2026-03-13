/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/13 17:37:36 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "MLX42.h"
#include "cleanup.h"
#include "error.h"
#include "parser.h"
#include "render.h"
#include "input.h"

#include <stddef.h>
#include <stdlib.h>

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	if (init_images(data))
	{
		cleanup(data);
		exit(1);
	}
	mlx_loop_hook(data->mlx, render_map, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx); // NOTE: is there a function to break the loop?
	mlx_terminate(data->mlx);
	return (0);
}

int	init_data(t_data *data)
{
	data->map = ft_calloc(1, sizeof(*data->map));
	if (!data->map)
		return (pr_error("malloc\n"), 1);
	data->img = ft_calloc(1, sizeof(*data->img));
	if (!data->img)
		return (pr_error("malloc\n"), 1);
	data->raycast = ft_calloc(1, sizeof(*data->raycast));
	if (!data->raycast)
		return (pr_error("malloc\n"), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
		return (pr_error("Please enter a .cub file\n"), 1);
	if (init_data(&data))
		return (1);
	if (parser(data.map, argv[1]))
		return (1);
	init_values(data.map);
	if (init_mlx(&data))
		return (1);
	return (0);
}
