/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:32:16 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/06 19:45:57 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"
#include <math.h>

void	matrix_rotation(double *x, double *y, double rotspeed)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;

	*x = old_x * cos(rotspeed) - old_y * sin(rotspeed);
	*y = old_y * cos(rotspeed) + old_x * sin(rotspeed);
}

int	rotation(t_mapdata *mapdata)
{
	mapdata->rotspeed = 0.02;

	return (0);
}

