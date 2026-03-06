/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:42:01 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/03 18:28:47 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "get_next_line.h"
#include "ft_malloc_lite.h"
#include <stdlib.h>

static int	check_chars(int *spawnp, const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && !line[i + 1])
			break ;
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			(*spawnp)++;
		if (!ft_isspace(line[i]) && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != '0' && line[i] != '1')
			return (pr_error("invalid map char\n"), 1);
		++i;
	}
	return (0);
}

int	validate_map(int fd, char ***map)
{
	char	*tmp;
	size_t	rows;
	int		spawnp;

	rows = 0;
	spawnp = 0;
	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n' && (free(tmp), 1))
		tmp = get_next_line(fd);
	while (tmp && tmp[0] != '\n')
	{
		if (check_chars(&spawnp, tmp))
			return (free(tmp), 1);
		*map = ft_realloc_lite(*map, sizeof(char *) * (rows + 1));
		if (!*map)
			return (free(tmp), pr_error("realloc failed\n"), 1);
		(free(0), (*map)[rows++] = tmp, tmp = get_next_line(fd));
	}
	*map = ft_realloc_lite(*map, sizeof(char *) * (rows + 1));
	if (!*map)
		return (pr_error("realloc failed\n"), (tmp && (free(tmp), 1), 1));
	(*map)[rows] = NULL;
	if (spawnp != 1)
		return (pr_error("not one spawn point\n"), (tmp && (free(tmp), 1)), 1);
	return ((tmp && (free(tmp), 1)), 0);
}
