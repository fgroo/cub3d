/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:30:42 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/10 15:17:50 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"
# include "MLX42.h"

# define MOVEMENT_SPEED 4.0
# define ROT_SPEED 0.2

void	moving(t_mapdata *map, double delta_time, char direction);
void	matrix_rotation(double *x, double *y, double rot_speed, double delta_time);
void	init_values(t_mapdata *m);
void	key_hook(mlx_key_data_t keycode, void *param);

#endif
