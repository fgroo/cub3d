/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:32:16 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/23 18:01:00 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "input.h"

#include <math.h>
#include <stdlib.h>

#define HB 0.01

static	int	if_no_wall(t_mapdata *map, double new_x, double new_y)
{
	if (is_wall(map, (int)(new_x - HB), (int)(new_y - HB))
		|| is_wall(map, (int)(new_x + HB), (int)(new_y - HB))
		|| is_wall(map, (int)(new_x - HB), (int)(new_y + HB))
		|| is_wall(map, (int)(new_x + HB), (int)(new_y + HB)))
		return (0);
	return (1);
}

void	matrix_rotation(double *x, double *y, double rotspeed)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(rotspeed) - old_y * sin(rotspeed);
	*y = old_y * cos(rotspeed) + old_x * sin(rotspeed);
}

static void	calc_new_pos(t_mapdata *map, char d, double *new_x, double *new_y)
{
	*new_x = map->player_pos.x;
	*new_y = map->player_pos.y;
	if (d == 'W')
	{
		*new_x += map->player_view.x * MOVEMENT_SPEED;
		*new_y += map->player_view.y * MOVEMENT_SPEED;
	}
	else if (d == 'S')
	{
		*new_x -= map->player_view.x * MOVEMENT_SPEED;
		*new_y -= map->player_view.y * MOVEMENT_SPEED;
	}
	else if (d == 'A')
	{
		*new_x += map->player_view.y * MOVEMENT_SPEED;
		*new_y -= map->player_view.x * MOVEMENT_SPEED;
	}
	else if (d == 'D')
	{
		*new_x -= map->player_view.y * MOVEMENT_SPEED;
		*new_y += map->player_view.x * MOVEMENT_SPEED;
	}
}

void	moving(t_mapdata *map, char direction)
{
	double	new_x;
	double	new_y;

	if (!map || !map->map)
		return ;
	calc_new_pos(map, direction, &new_x, &new_y);
	if (if_no_wall(map, new_x, map->player_pos.y))
		map->player_pos.x = new_x;
	if (if_no_wall(map, map->player_pos.x, new_y))
		map->player_pos.y = new_y;
}

void	init_values(t_mapdata *m)
{
	m->player_pos.x = m->spawn_coordinates.x + 0.5;
	m->player_pos.y = m->spawn_coordinates.y + 0.5;
	if (m->spawn_orientation == 'N')
		(free(0), m->player_view.x = 0, m->player_view.y = -1,
			free(0), m->cam_plane.x = FOV, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'S')
		(free(0), m->player_view.x = 0, m->player_view.y = 1,
			free(0), m->cam_plane.x = -FOV, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'E')
		(free(0), m->player_view.x = 1, m->player_view.y = 0,
			free(0), m->cam_plane.x = 0, m->cam_plane.y = FOV);
	else if (m->spawn_orientation == 'W')
		(free(0), m->player_view.x = -1, m->player_view.y = 0,
			free(0), m->cam_plane.x = 0, m->cam_plane.y = -FOV);
}
