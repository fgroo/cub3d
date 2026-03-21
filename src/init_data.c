/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 01:40:00 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/21 01:40:00 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cleanup.h"
#include "error.h"
#include "libft.h"

uint32_t	adjust(uint32_t resolution)
{
	if (resolution % 8 == 0)
		return (resolution);
	else if (resolution % 8 >= 4)
		return (resolution + resolution % 8);
	return (resolution - resolution % 8);
}

int	init_data(t_data *data)
{
	const uint32_t	detail_level = 1;

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
