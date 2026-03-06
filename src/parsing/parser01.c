/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:45 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/05 15:15:28 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "get_next_line.h"
#include "error.h"
#include "cleanup.h"
#include "debug.h"
#include <stdlib.h>
#include <fcntl.h>

static int	check_texture_file(char **tex, char *line, char *identifier)
{
	*tex = fetch_texture_file(line, identifier);
	if (!(*tex) && (free(line), 1))
		return (pr_error("failed fetching texture file\n"), 1);
	return (0);
}

static int	check_fetch_color(t_mapdata **mapdata, char *line,
	char *identifier, int i)
{
	if (i == 4)
	{
		(*mapdata)->floor_color = fetch_color(line, identifier);
		if ((*mapdata)->floor_color == -1)
			return (pr_error("failed fetching color"), 1);
	}
	else if (i == 5)
	{
		(*mapdata)->ceiling_color = fetch_color(line, identifier);
		if ((*mapdata)->ceiling_color == -1)
			return (pr_error("failed fetching color"), 1);
	}
	return (0);
}

int	validate_format(int fd, t_mapdata *mapdata)
{
	static char	format[7][3] = {"NO", "SO", "WE", "EA", "F", "C", {0}};
	char		*tmp;
	int			i;

	i = 0;
	while (i < 6)
	{
		tmp = NULL;
		tmp = get_next_line(fd);
		if (!tmp)
			return (pr_error("GNL\n"), 1);
		if (tmp[0] == '\n' && (free(tmp), 1))
			continue ;
		if (ft_strncmp(tmp, format[i], ft_strlen(format[i])) && (free(tmp), 1))
			return (pr_error("Wrong Format\n"), 1);
		if (i < 4 && check_texture_file(&mapdata->tex[i], tmp, format[i]))
			return (1);
		else if (i >= 4 && check_fetch_color(&mapdata, tmp, format[i], i))
			return (1);
		++i;
		free(tmp);
	}
	return (0);
}

int	parser(t_mapdata *map, char *file)
{
	int	fd;

	if (!map)
		return (pr_error(""), 1);
	if ((ft_strcmp(file + (ft_strlen(file) - 4), ".cub")) != 0)
		return (free_mapdata(map), pr_error("Wrong file extension\n"), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free_mapdata(map), pr_error("open()\n"), 1);
	if (validate_format(fd, map))
		return (free_mapdata(map), close(fd), 1);
	if (validate_map(fd, &map->map))
		return (free_mapdata(map), close(fd), 1);
	if (flood_map(map))
		return (free_mapdata(map), close(fd), 1);
	print_mapdata(map);
	free_mapdata(map);
	close(fd);
	return (0);
}
