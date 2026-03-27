/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:45 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/27 15:34:27 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "get_next_line.h"
#include "error.h"
#include "cleanup.h"
#include "debug.h"
#include <stdlib.h>
#include <fcntl.h>

static int	is_complete(int *flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (flag[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	validate_format(int fd, t_mapdata *mapdata, char **saved)
{
	static const char	*format[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	static int			flag[7];
	char				*tmp;

	*saved = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && is_complete(flag))
			return (0);
		if (!tmp)
			return (pr_error("incomplete config\n"), 1);
		if (tmp[0] == '\n' && (free(tmp), 1))
			continue ;
		if (is_complete(flag))
		{
			if (is_config_identifier(format, tmp))
				return (free(tmp), pr_error("configline already taken\n"), 1);
			*saved = tmp;
			return (0);
		}
		if (!does_mapfile_align(flag, format, tmp, mapdata))
			return (free(tmp), 1);
		free(tmp);
	}
}

static int	check_extension(const char *file)
{
	const char	*base;
	const char	*dot;

	base = ft_strrchr(file, '/');
	if (!base)
		base = file;
	else
		++base;
	dot = ft_strchr(base, '.');
	if (!dot || ft_strcmp(dot, ".cub") != 0)
		return (1);
	return (0);
}

int	parser(t_mapdata *map, char *file)
{
	int		fd;
	char	*saved;

	saved = NULL;
	if (!map)
		return (pr_error(""), 1);
	if (check_extension(file))
		return (pr_error("Wrong file extension\n"), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (pr_error("open()\n"), 1);
	if (validate_format(fd, map, &saved))
		return (close(fd), 1);
	if (validate_map(fd, &map->map, saved))
		return (close(fd), 1);
	if (flood_map(map))
		return (close(fd), 1);
	if (map_size(map, &map->width, &map->height))
		return (close(fd), 1);
	if (DEBUG)
		print_mapdata(map);
	close(fd);
	return (0);
}
