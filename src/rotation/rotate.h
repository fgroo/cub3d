/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:30:42 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/07 20:52:22 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "cub3d.h"
# include "libft.h"

void	moving(t_mapdata *map, char direction);
void	matrix_rotation(double *x, double *y, double rotspeed);
void	init_values(t_mapdata *m);

#endif