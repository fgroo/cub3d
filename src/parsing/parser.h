#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define WEST_ID "WE"
# define EAST_ID "EA"
# define FLOOR_ID "F"
# define CEILING_ID "C"

int parser(t_mapdata *map, char *argv[]);

#endif // !PARSER_H
