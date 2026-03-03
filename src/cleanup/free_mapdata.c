/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:20:00 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/03 15:23:04 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "ft_malloc_lite.h"
#include <stdlib.h>

static void	free_map_rows(t_mapdata *map)
{
	int	i;

	if (!map->map)
		return ;
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	ft_free(map->map);
}

void	free_mapdata(t_mapdata *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < 4)
	{
		if (map->tex[i])
			free(map->tex[i]);
		i++;
	}
	free_map_rows(map);
	free(map);
}
