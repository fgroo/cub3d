/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:47:44 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/20 13:47:10 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"
#include <math.h>
#include <stdio.h>

extern bool is_front_ray;

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

static int
	get_tex_x(mlx_texture_t *texture, t_raycast *ray, t_vector player_pos)
{
	double	wall_x;
	int		tex_x;

	if (ray->side_dist_x < ray->side_dist_y)
		wall_x = player_pos.y + ray->hit_dist * ray->ray_dir.y;
	else
		wall_x = player_pos.x + ray->hit_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	if(is_front_ray)
	{
		printf("hit_dist: %f\n", ray->hit_dist);
		if (ray->side_dist_x < ray->side_dist_y)
		{
			printf("ray_dir.y: %f\n", ray->ray_dir.y);
			printf("player_pos.y: %f\n", player_pos.y);
		}
		else
		{
			printf("ray_dir.x: %f\n", ray->ray_dir.x);
			printf("player_pos.x: %f\n", player_pos.x);
		}
		printf("wall_x: %f\n", wall_x);
	}
	tex_x = (int)(wall_x * (double)(texture->width));
// hit_dist: 1.958915
// ray_dir.y: -0.765730
// player_pos.y: 5.500000
// wall_x: 0.000000
	if (ray->side_dist_x < ray->side_dist_y && ray->ray_dir.x > 0)
		return((int)texture->width - tex_x - 1);
	if (ray->side_dist_x >= ray->side_dist_y && ray->ray_dir.y < 0)
		return((int)texture->width - tex_x - 1);
	return(tex_x);
}

void	map_texture_to_vertical(t_texmap *vert, mlx_image_t *img, t_data *data,
								t_raycast *ray)
{
	vert->texture = get_wall_texture(data->textures, ray->hit_side);
	vert->line_height = (int)((double)img->height / ray->hit_dist);
	vert->draw_start = -vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_start < 0)
		vert->draw_start = 0;
	vert->draw_end = (int)vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_end >= (int)img->height)
		vert->draw_end = (int)img->height - 1;
	vert->tex_x = get_tex_x(vert->texture, ray, data->map->player_pos);
	vert->step = 1.0 * vert->texture->height / vert->line_height;
	vert->tex_pos = (vert->draw_start - (double)img->height / 2 + \
		(double)vert->line_height / 2) * vert->step;
}
