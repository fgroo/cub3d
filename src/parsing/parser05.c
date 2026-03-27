/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:41:47 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/27 15:34:05 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

static int	check_texture_file(char **tex, char *line, const char *identifier)
{
	*tex = fetch_texture_file(line, identifier);
	if (!(*tex))
		return (pr_error("failed fetching texture file\n"), 1);
	return (0);
}

static int	check_fetch_color(t_mapdata *mapdata, char *line,
	const char *identifier, int i)
{
	if (i == 4)
	{
		if (fetch_color(line, identifier, &mapdata->floor_color) == 1)
			return (pr_error("failed fetching color\n"), 1);
	}
	else if (i == 5)
	{
		if (fetch_color(line, identifier, &mapdata->ceiling_color) == 1)
			return (pr_error("failed fetching color\n"), 1);
	}
	return (0);
}

static int	current_state(const char **format, char *tmp)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(tmp, format[i], ft_strlen(format[i])))
			return (i);
		else
			++i;
	}
	return (i);
}

int	does_mapfile_align(int *flag, const char **format,
		char *tmp, t_mapdata *map)
{
	int	i;

	if (!flag || !format || !map)
		return (pr_error("empty variables\n"), 0);
	i = current_state(format, tmp);
	if (i > 5)
		return (pr_error("Wrong Format\n"), 0);
	if (flag[i] == 1)
		return (pr_error("configline already taken\n"), 0);
	if (i < 4 && check_texture_file(&map->tex[i], tmp, format[i]))
		return (0);
	else if (i >= 4 && check_fetch_color(map, tmp, format[i], i))
		return (0);
	flag[i] = 1;
	return (1);
}

int	is_config_identifier(const char **format, char *line)
{
	return (current_state(format, line) <= 5);
}
