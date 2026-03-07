/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/08 00:22:48 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "error.h"
#include "parser.h"
#include "MLX42.h"
#include "rotate.h"
#include "MLX42.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx); // is there a function to break the loop?
	mlx_terminate(data->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data		data;

	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
		return (pr_error("Please enter a .cub file\n"), 1);
	data.map = ft_calloc(1, sizeof(*data.map));
	if (!data.map)
		return (pr_error("malloc\n"), 1);
	if (parser(data.map, argv[1]))
		return (1);
	init_values(data.map);
	if (init_mlx(&data))
		return (1);
	return (0);
}
