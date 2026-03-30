/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:37:00 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/30 21:28:49 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

static int	rev_floodfill(char **map, size_t row, size_t column)
{
	if (column >= ft_strlen(map[row]))
		return (0);
	map[row][column] = '0';
	if (row && column < ft_strlen(map[row - 1])
		&& map[row - 1][column] == '2')
		rev_floodfill(map, row - 1, column);
	if (column && map[row][column - 1] == '2')
		rev_floodfill(map, row, column - 1);
	if (map[row + 1] && column < ft_strlen(map[row + 1])
		&& map[row + 1][column] == '2')
		rev_floodfill(map, row + 1, column);
	if (map[row][column + 1] && map[row][column + 1] == '2')
		rev_floodfill(map, row, column + 1);
	return (0);
}

static int	floodfill(char **map, size_t row, size_t column, int *err)
{
	if (!row || !column || !map[row + 1] || !map[row - 1]
		|| column >= ft_strlen(map[row])
		|| column > ft_strlen(map[row + 1])
		|| column > ft_strlen(map[row - 1]))
		return (++(*err));
	if (!map[row][column + 1]
		|| !map[row][column] || ft_isspace(map[row][column]))
		return ((map[row][column] && (map[row][column] = '2')), ++(*err));
	map[row][column] = '2';
	if (column < ft_strlen(map[row - 1])
		&& (map[row - 1][column] == '0' || ft_isspace(map[row - 1][column])))
		floodfill(map, row - 1, column, err);
	if (map[row][column - 1] == '0'
		|| ft_isspace(map[row][column - 1]))
		floodfill(map, row, column - 1, err);
	if (column < ft_strlen(map[row + 1])
		&& (map[row + 1][column] == '0' || ft_isspace(map[row + 1][column])))
		floodfill(map, row + 1, column, err);
	if (map[row][column + 1] == '0'
		|| ft_isspace(map[row][column + 1]))
		floodfill(map, row, column + 1, err);
	return (*err);
}

static void	assigning(t_mapdata *mapdata, char **map, int row, int column)
{
	mapdata->spawn_orientation = map[row][column];
	mapdata->spawn_coordinates.x = (int)column;
	mapdata->spawn_coordinates.y = (int)row;
}

int	flood_map(t_mapdata *mapdata)
{
	size_t	row;
	size_t	column;
	char	**map;

	map = mapdata->map;
	row = 0;
	column = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column] && map[row][column] != 'N'
			&& map[row][column] != 'S' && map[row][column] != 'E'
			&& map[row][column] != 'W')
			++column;
		if (map[row][column] == 'N' || map[row][column] == 'S'
			|| map[row][column] == 'E' || map[row][column] == 'W')
			break ;
		++row;
	}
	assigning(mapdata, map, (int)row, (int)column);
	if (floodfill(map, row, column, &(int){0}))
		return (pr_error("failed floodfill\n"), 1);
	rev_floodfill(map, row, column);
	return (0);
}

int	map_size(t_mapdata *map, int *width, int *height)
{
	int	len;

	if (!map || !map->map ||!map->map[0])
	{
		pr_error("map_size(): failed to get map size\n");
		return (1);
	}
	*height = 0;
	*width = 0;
	while (map->map[*height])
	{
		len = (int)ft_strlen(map->map[*height]);
		if (len > *width)
			*width = len;
		++(*height);
	}
	if (*height >= MAX_ROW || *width >= MAX_COLUMN)
		return (pr_error("map to big\n"), 1);
	return (0);
}
