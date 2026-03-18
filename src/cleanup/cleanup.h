/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:35:09 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/18 12:30:23 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "cub3d.h"

void	free_double_array(char **array);
void	free_mapdata(t_mapdata *map);
void	free_images(mlx_t *mlx, t_image *image);
void	free_raycast(t_raycast *raycast);
int		cleanup(t_data *data);

#endif
