/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:30:42 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/06 19:47:05 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "cub3d.h"
# include "libft.h"

void	matrix_rotation(double *x, double *y, double rotspeed);
int		rotation(t_mapdata *mapdata);

#endif