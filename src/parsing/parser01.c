/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:45 by fgroo             #+#    #+#             */
/*   Updated: 2026/02/26 15:38:39 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return (printf("Error\n"), 1);
// return (printf("Error\nWrong Format\n"), 1);


#include "parser.h"

#include "error.h"
#include "libft.h"

#include <stdio.h>
#include <fcntl.h>

int validate_format(int fd, t_mapdata *mapdata)
{
	static char format[7][4] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", {0}};
	char		*tmp;
	int			i;

	i = 0;
	while (i < 4)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			pr_error("GNL\n");
		if (ft_strncmp(tmp, format[i], 3))
			pr_error("Wrong Format\n");
		mapdata->tex[i++] = tmp;
	}
	tmp = get_next_line(fd);

	return (0);
}

int parser(t_mapdata *map, char *argv[])
{
	int fd;

	if (!map)
		return (pr_error(""), 1);
	if (ft_strcmp(argv[1], ".cub"))
		return (pr_error("Wrong file extension\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (pr_error("open()\n"), 1);
	if (validate_format(fd, map))
		return (1);
	return (0);
}


// TODO: 
// 1. 
