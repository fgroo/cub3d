/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:32:16 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/10 15:09:21 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "input.h"

#include <math.h>
#include <stdlib.h>

void	matrix_rotation(double *x, double *y, double rot_speed, double delta_t)
{
	double	old_x;
	double	old_y;

	(void)delta_t;
	old_x = *x;
	old_y = *y;
	*x = old_x * cos(rot_speed) - old_y * sin(rot_speed); // * delta_t;
	*y = old_y * cos(rot_speed) + old_x * sin(rot_speed); // * delta_t;
}

void	moving(t_mapdata *map, double delta_t, char direction)
{
	if (!map || !map->map)
		return ;
	if (direction == 'W')
	{
		map->player_pos.x += map->player_view.x * MOVEMENT_SPEED * delta_t;
		map->player_pos.y += map->player_view.y * MOVEMENT_SPEED * delta_t;
	}
	else if (direction == 'A')
	{
		map->player_pos.x += map->player_view.y * MOVEMENT_SPEED * delta_t;
		map->player_pos.y -= map->player_view.x * MOVEMENT_SPEED * delta_t;
	}
	else if (direction == 'S')
	{
		map->player_pos.x -= map->player_view.x * MOVEMENT_SPEED * delta_t;
		map->player_pos.y -= map->player_view.y * MOVEMENT_SPEED * delta_t;
	}
	else if (direction == 'D')
	{
		map->player_pos.x -= map->player_view.y * MOVEMENT_SPEED * delta_t;
		map->player_pos.y += map->player_view.x * MOVEMENT_SPEED * delta_t;
	}
}

void	init_values(t_mapdata *m)
{
	m->rotspeed = 0.06; // i dont know where this value should come from
	if (m->spawn_orientation == 'N')
		(free(0), m->player_pos.x = m->spawn_coordinates.x + 0.5,
		m->player_pos.y = m->spawn_coordinates.y + 0.5, m->player_view.x = 0,
		m->player_view.y = -1, m->cam_plane.x = 0.66, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'S')
		(free(0), m->player_pos.x = m->spawn_coordinates.x + 0.5,
		m->player_pos.y = m->spawn_coordinates.y + 0.5, m->player_view.x = 0,
		m->player_view.y = 1, m->cam_plane.x = -0.66, m->cam_plane.y = 0);
	else if (m->spawn_orientation == 'E')
		(free(0), m->player_pos.x = m->spawn_coordinates.x + 0.5,
		m->player_pos.y = m->spawn_coordinates.y + 0.5, m->player_view.x = 1,
		m->player_view.y = 0, m->cam_plane.x = 0, m->cam_plane.y = 0.66);
	else if (m->spawn_orientation == 'W')
		(free(0), m->player_pos.x = m->spawn_coordinates.x + 0.5,
		m->player_pos.y = m->spawn_coordinates.y + 0.5, m->player_view.x = -1,
		m->player_view.y = 0, m->cam_plane.x = 0, m->cam_plane.y = -0.66);
}

