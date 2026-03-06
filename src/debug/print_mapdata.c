/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mapdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:29:55 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/03 18:29:56 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"
#include <stdio.h>

static void	print_textures_and_colors(t_mapdata *map)
{
	int	i;

	printf("--- t_mapdata ---\n");
	i = 0;
	while (i < 4)
	{
		if (map->tex[i])
			printf("tex[%d]: %s\n", i, map->tex[i]);
		else
			printf("tex[%d]: (null)\n", i);
		i++;
	}
	printf("floor_color: %d\n", map->floor_color);
	printf("ceiling_color: %d\n", map->ceiling_color);
}

void	print_mapdata(t_mapdata *map)
{
	int	i;

	if (!map)
	{
		printf("Mapdata is NULL\n");
		return ;
	}
	print_textures_and_colors(map);
	if (map->map)
	{
		printf("map:\n");
		i = 0;
		while (map->map[i])
		{
			printf("  [%d]: %s\n", i, map->map[i]);
			i++;
		}
	}
	else
	{
		printf("map: (null)\n");
	}
	printf("-----------------\n");
}
