/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:32:16 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/07 20:52:10 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"
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
	double	movespeed; // i dont know where i get this;

	movespeed = 0.2;
	if (!map || !map->map)
		return ;
	if (direction == 'W')
	{
		map->player_pos.x += map->player_view.x * movespeed;
		map->player_pos.y += map->player_view.y * movespeed;
	}
	else if (direction == 'A')
	{
		map->player_pos.x += map->player_view.y * movespeed;
		map->player_pos.y -= map->player_view.x * movespeed;
	}
	else if (direction == 'S')
	{
		map->player_pos.x -= map->player_view.x * movespeed;
		map->player_pos.y -= map->player_view.y * movespeed;
	}
	else if (direction == 'D')
	{
		map->player_pos.x -= map->player_view.y * movespeed;
		map->player_pos.y += map->player_view.x * movespeed;
	}
}

void	init_values(t_mapdata *m)
{
	m->rotspeed = 0.02; // i dont know where this value should come from
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

