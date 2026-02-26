/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:45 by fgroo             #+#    #+#             */
/*   Updated: 2026/02/26 20:48:37 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return (printf("Error\n"), 1);
// return (printf("Error\nWrong Format\n"), 1);

#include "parser.h"
#include "error.h"
#include "libft.h"

#include <stdio.h>
#include <fcntl.h>

static int	check_texture_file(char *tex, char *line, char *identifier)
{
	tex = fetch_texture_file(line, identifier);
	if (!tex && (free(line), 1))
		return (pr_error("failed fetching texture file\n"), 1);
	return (0);
}

static int	check_fetch_color(t_mapdata *mapdata, char *line,
	char *identifier, int i)
{
	if (i == 5)
	{
		mapdata->floor_color = fetch_color(line, identifier);
		if (mapdata->floor_color == -1)
			return (pr_error("failed fetching color"), 1);
	}
	else if (i == 6)
	{
		mapdata->ceiling_color = fetch_color(line, identifier);
		if (mapdata->ceiling_color == -1)
			return (pr_error("failed fetching color"), 1);
	}
	return (0);
}

int	validate_format(int fd, t_mapdata *mapdata)
{
	static char	format[7][3] = {"NO", "SO", "WE", "EA", "F", "C", {0}};
	char		*tmp;
	int			i;

	i = -1;
	while (++i < 6)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return (pr_error("GNL\n"), 1);
		if (tmp[0] == '\n' && (free(tmp), 1))
			continue ;
		if (ft_strncmp(tmp, format[i], ft_strlen(format[i])) && (free(tmp), 1))
			return (pr_error("Wrong Format\n"), 1);
		if (i < 4 && check_texture_file(mapdata->tex[i], tmp, format[i]))
			return (1);
		else if (i >= 4 && check_fetch_color(mapdata, tmp, format[i], i))
			return (1);
	}
	return (0);
}

char	**hardcoded(char ***argv)
{
	char		**hardcode;
	static char	arg[] = "./maps/example.cub";
	int			i;

	i = 0;
	while (*argv[i])
		*argv[i++] = NULL;
	hardcode = malloc(sizeof(char *) * 2);
	if (!hardcode)
		return (pr_error("malloc\n"), NULL);
	hardcode[0] = malloc(sizeof(ft_strlen(arg)) + 1);
	if (!hardcode[0])
		return (pr_error("malloc\n"), NULL);
	hardcode[0] = arg;
	hardcode[1] = NULL;
	return (hardcode);
}

int	parser(t_mapdata *map, char *argv[])
{
	int	fd;

	if (!map)
		return (pr_error(""), 1);
	argv = hardcoded(&argv);
	if ((ft_strcmp(argv[0] + (ft_strlen(argv[0]) - 4), ".cub")) != 0) // hardcoded for testing
		return (pr_error("Wrong file extension\n"), 1);
	fd = open(argv[0], O_RDONLY); // is 0, which is wrong for real use case
	if (fd == -1)
		return (pr_error("open()\n"), 1);
	if (validate_format(fd, map))
		return (1);
	return (0);
}
