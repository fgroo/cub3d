/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:48:01 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/20 12:08:11 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_INT_H
# define RENDER_INT_H

#include "MLX42.h"
#include "cub3d.h"

typedef struct s_texmap
{
	mlx_texture_t	*texture;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				line_thickness;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_texmap;

void	map_texture_to_vertical(t_texmap *vert, mlx_image_t *img, t_data *data,
								t_raycast *ray);

#endif // !RENDER_INT_H
