/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:39:36 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/27 13:40:28 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"
# include "libft.h" // is getting used everywhere

# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define WEST_ID "WE"
# define EAST_ID "EA"
# define FLOOR_ID "F"
# define CEILING_ID "C"

int			parser(t_mapdata *map, char *file);
int			validate_format(int fd, t_mapdata *mapdata, char **saved);
uint32_t	to_hex_color(long r, long g, long b);
int			fetch_color(char *line, const char *identifier, uint32_t *color);
char		*fetch_texture_file(const char *line, const char *identifier);
int			validate_map(int fd, char ***map, char *saved);
int			flood_map(t_mapdata *mapdata);
int			map_size(t_mapdata *map, int *width, int *height);
int			does_mapfile_align(int *flag, const char **format,
				char *tmp, t_mapdata *map);
int			is_config_identifier(const char **format, char *line);

#endif // !PARSER_H
