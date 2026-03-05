/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:37:00 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/05 15:24:02 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

static int	floodfill(char ***map, size_t row, size_t column, int *err)
{
	if (!row || !column || !(*map)[row][column]
		|| ft_isspace((*map)[row][column]))
		return (((*map)[row][column] && ((*map)[row][column] = '2')), ++(*err));
	(*map)[row][column] = '2';
	if ((*map)[row - 1][column] == '0' || ft_isspace((*map)[row - 1][column]))
		floodfill(map, row - 1, column, err);
	else if ((*map)[row][column - 1] == '0'
		|| ft_isspace((*map)[row][column - 1]))
		floodfill(map, row, column - 1, err);
	else if ((*map)[row + 1][column] == '0'
		|| ft_isspace((*map)[row + 1][column]))
		floodfill(map, row + 1, column, err);
	else if ((*map)[row][column + 1] == '0'
		|| ft_isspace((*map)[row][column + 1]))
		floodfill(map, row, column + 1, err);
	return (*err);
}

int	flood_map(t_mapdata *mapdata)
{
	size_t	row;
	size_t	column;
	char	***map;

	map = &mapdata->map;
	row = 0;
	column = 0;
	while ((*map)[row] && (*map)[row][column] != 'N'
			&& (*map)[row][column] != 'S' && (*map)[row][column] != 'E'
			&& (*map)[row][column] != 'W' && ++row)
	{
		column = 0;
		while ((*map)[row][column] && (*map)[row][column] != 'N'
			&& (*map)[row][column] != 'S' && (*map)[row][column] != 'E'
			&& (*map)[row][column] != 'W')
			++column;
	}
	mapdata->spawn_orientation = (*map)[row][column];
	mapdata->spawn_coordinates.x = (int)column;
	mapdata->spawn_coordinates.y = (int)row;
	if (floodfill(map, row, column, &(int){0}))
		return (pr_error("failed floodfill\n"), 1);
	return (0);
}
