/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:52:36 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/17 16:11:59 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

#include <stdlib.h>

/*  Pass a line from the .cub file to extract the path of the texturefile.
 *  Example:
 *  void foo()
 *  {
 *		...
 *		char *line = get_next_line(fd);
 *		if (!line)
 *			return (NULL);
 *		char *tex = fetch_texture_file(line, "NO");
 *		...
 *  }
 */
char	*fetch_texture_file(const char *line, const char *identifier)
{
	char	*tex;
	size_t	len;
	size_t	j;

	len = 0;
	while (*line && *identifier && *line == *identifier && identifier++)
		++line;
	if (*identifier != '\0')
		return (NULL);
	while (*line && ft_isspace(*line))
		++line;
	if (*line == '\0')
		return (NULL);
	len = 0;
	while (line[len] && !ft_isspace(line[len]))
		++len;
	j = 0;
	while (line[len + j] && ft_isspace(line[len + j]))
		++j;
	if (line[len + j] != '\0')
		return (NULL);
	tex = ft_strndup(line, len);
	return (tex);
}

uint32_t	to_hex_color(long r, long g, long b)
{
	return ((uint32_t)((r << 24) | (g << 16) | (b << 8) | 0xFF));
}

static int	parse_color(char *line, long rgb[3])
{
	size_t	i;
	char	*endptr;

	i = 0;
	while (*line && i < 3)
	{
		rgb[i++] = ft_strtol(line + (*line == ','), &endptr, 10);
		if (endptr == line)
			return (1);
		while (*endptr && ft_isspace(*endptr))
			++endptr;
		if (*endptr != ',' && i != 3)
			return (1);
		line = endptr;
	}
	if (i != 3 || *endptr)
		return (1);
	return (0);
}

int	fetch_color(char *line, const char *identifier, uint32_t *color)
{
	long	rgb[3];

	while (*line && *identifier && *line == *identifier++)
		++line;
	if (*identifier != '\0')
		return (1);
	while (*line && ft_isspace(*line))
		++line;
	if (parse_color(line, rgb) == 1)
		return (1);
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0
		|| rgb[0] > 255 || rgb[1]> 255 || rgb[2] > 255)
		return (1);
	*color = to_hex_color(rgb[0], rgb[1], rgb[2]);
	return (0);
}
