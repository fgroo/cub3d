/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:32:16 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/19 21:38:41 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "input.h"

#include <math.h>
#include <stdlib.h>

void	matrix_rotation(double *x, double *y, double rotspeed)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(rotspeed) - old_y * sin(rotspeed);
	*y = old_y * cos(rotspeed) + old_x * sin(rotspeed);
}

void	moving(t_mapdata *map, char direction)
{
	if (!map || !map->map)
		return ;
	if (direction == 'W')
	{
		map->player_pos.x += map->player_view.x * MOVEMENT_SPEED;
		map->player_pos.y += map->player_view.y * MOVEMENT_SPEED;
	}
	else if (direction == 'A')
	{
		map->player_pos.x += map->player_view.y * MOVEMENT_SPEED;
		map->player_pos.y -= map->player_view.x * MOVEMENT_SPEED;
	}
	else if (direction == 'S')
	{
		map->player_pos.x -= map->player_view.x * MOVEMENT_SPEED;
		map->player_pos.y -= map->player_view.y * MOVEMENT_SPEED;
	}
	else if (direction == 'D')
	{
		map->player_pos.x -= map->player_view.y * MOVEMENT_SPEED;
		map->player_pos.y += map->player_view.x * MOVEMENT_SPEED;
	}
}

void	init_values(t_mapdata *m)
{
	m->rotspeed = 0.06;
	m->player_pos.x = m->spawn_coordinates.x + 0.5;
	m->player_pos.y = m->spawn_coordinates.y + 0.5;
	if (m->spawn_orientation == 'N')
		(free(0), m->player_view.x = 0, m->player_view.y = -1,
			free(0), m->cam_plane.x = 0.66, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'S')
		(free(0), m->player_view.x = 0, m->player_view.y = 1,
			free(0), m->cam_plane.x = -0.66, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'E')
		(free(0), m->player_view.x = 1, m->player_view.y = 0,
			free(0), m->cam_plane.x = 0, m->cam_plane.y = 0.66);
	else if (m->spawn_orientation == 'W')
		(free(0), m->player_view.x = -1, m->player_view.y = 0,
			free(0), m->cam_plane.x = 0, m->cam_plane.y = -0.66);
}
