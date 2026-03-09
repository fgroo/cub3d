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

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"
# include "MLX42.h"

# define MOVEMENT_SPEED 0.1

void	moving(t_mapdata *map, char direction);
void	matrix_rotation(double *x, double *y, double rotspeed);
void	init_values(t_mapdata *m);
void	key_hook(mlx_key_data_t keycode, void *param);

#endif
