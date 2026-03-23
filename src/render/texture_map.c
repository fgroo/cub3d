/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:47:44 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/21 19:10:57 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"
#include <math.h>
#include <stdio.h>

static mlx_texture_t	*get_wall_texture(t_textures *textures, char side)
{
	if (side == 'N')
		return (textures->north_wall);
	else if (side == 'E')
		return (textures->east_wall);
	else if (side == 'S')
		return (textures->south_wall);
	else if (side == 'W')
		return (textures->west_wall);
	return (textures->north_wall);
}

int	get_line_height(uint32_t texture_height, double hit_dist)
{
	double	line_height;
	double	epsilon;

	epsilon = 1e-7;
	if (hit_dist < 0)
		epsilon = -epsilon;
	line_height = (double)texture_height / (hit_dist + epsilon);
	return ((int)line_height);
}

static int	get_tex_x(mlx_texture_t *texture, t_raycast *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->hit_side == 'N' || ray->hit_side == 'S')
		wall_x = ray->hit.x - floor(ray->hit.x);
	else
		wall_x = ray->hit.y - floor(ray->hit.y);
	tex_x = (int)(wall_x * (double)texture->width);
	if (ray->hit_side == 'N' || ray->hit_side == 'E')
		tex_x = (int)texture->width - tex_x - 1;
	return (tex_x);
}

void	map_texture_to_vertical(t_texmap *vert, mlx_image_t *img,
								t_textures *textures, t_raycast *ray)
{
	vert->texture = get_wall_texture(textures, ray->hit_side);
	vert->line_height = get_line_height(vert->texture->height, ray->hit_dist);
	vert->draw_start = -vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_start < 0)
		vert->draw_start = 0;
	vert->draw_end = (int)vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_end >= (int)img->height)
		vert->draw_end = (int)img->height - 1;
	vert->tex_x = get_tex_x(vert->texture, ray);
	vert->step = 1.0 * vert->texture->height / vert->line_height;
	vert->tex_pos = (vert->draw_start - (double)img->height / 2 + \
		(double)vert->line_height / 2) * vert->step;
}
