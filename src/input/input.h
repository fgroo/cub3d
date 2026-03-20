/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:30:42 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/18 21:34:44 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"
# include "MLX42.h"

# define MOVEMENT_SPEED 0.1

void		moving(t_mapdata *map, char direction);
void		matrix_rotation(double *x, double *y, double rotspeed);
void		init_values(t_mapdata *m);
void		input_hook(void *param);
void		dda(t_vector start, t_vector end, mlx_image_t *img);
void		draw_rays(t_data *data);
t_vector	raycast_wall_hit(t_mapdata *map, t_raycast *ray);
int			is_wall(t_mapdata *map, int x, int y);

#endif
