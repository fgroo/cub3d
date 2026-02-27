/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:42:01 by fgroo             #+#    #+#             */
/*   Updated: 2026/02/27 17:26:51 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "get_next_line.h"
#include <stdlib.h>

static size_t	align(size_t size)
{
	static size_t	alignment = 8;

	return (((size) + (alignment - 1)) & ~(alignment - 1));
}

void	*ft_realloc(void *ptr, size_t size) __attribute__((nonnull(1)));

void	*ft_realloc(void *p, size_t size)
{
	return (NULL);
}

int	check_chars(int	*spawnp, const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && !line[i + 1])
			break ;
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			*spawnp++;
		if (!ft_isspace(line[i]) || line[i] != 'N' || line[i] != 'S'
			|| line[i] != 'E' || line[i] != 'W'
			|| line[i] != '0' || line[i] != '1')
			return (pr_error("invalid map char\n"), 1);
		++i;
	}
	if (*spawnp > 1)
		return (pr_error("too many spawn points\n"), 1);
	return (0);
}

int	validate_map(int fd, char ***map)
{
	char			*tmp;
	static int		spawnp;

	(void)map;
	tmp = get_next_line(fd);
	while (tmp && *tmp == '\n' && (free(tmp), 1))
		tmp = get_next_line(fd);
	if (!tmp)
		return (pr_error("GNL\n"), 1);
	while (tmp)
	{
		if (check_chars(&spawnp, tmp))
			return (1);
	}
	if (!spawnp)
		return (pr_error("no spawn point\n"), 1);
	return (0);
}
