/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_textured.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:59:43 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 18:12:05 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"
#include "math.h"

#include <stdint.h>
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

// if (ray->side_dist_x < side_dist_y) == if (side == 0)
static void	draw_texture_vertical(mlx_image_t *img, t_vertical *vert, int idx)
{
	uint32_t	*pixels;
	uint32_t	color;
	int			y;
	int			x;

	pixels = (uint32_t *)vert->texture->pixels;
	y = vert->draw_start;
	while (y < vert->draw_end)
	{
		vert->tex_y = (int)vert->tex_pos & (int)(vert->texture->height - 1);
		vert->tex_pos += vert->step;
		color = pixels[vert->texture->width * \
			(uint32_t)vert->tex_y + (uint32_t)vert->tex_x];

		static int once = 0;
		if (once == 50)
		{
			printf("tex width: %d\n", vert->texture->width);
			printf("tex_y: %d\n", vert->tex_y);
			printf("tex_x: %d\n", vert->tex_x);
			printf("0x%x\n", vert->texture->pixels[0]);
			printf("0x%x\n", vert->texture->pixels[1]);
			printf("0x%x\n", vert->texture->pixels[2]);
			printf("0x%x\n", vert->texture->pixels[3]);
			printf("0x%x\n", color);
		}
		once++;

		x = 0;
		while (x < vert->line_thickness)
		{
			put_pixel(img, (uint32_t)(x + idx), (uint32_t)y, color);
			++x;
		}
		++y;
	}
}

void	init_vertical_data(t_vertical *vert, mlx_image_t *img, t_data *data, t_raycast *ray)
{
	vert->texture = get_wall_texture(data->textures, ray->hit_side);
	vert->line_height = (int)(img->height / ray->hit_dist);
	vert->draw_start = -vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_start < 0)
		vert->draw_start = 0;
	vert->draw_end = vert->line_height / 2 + (int)img->height / 2;
	if (vert->draw_end >= (int)img->height)
		vert->draw_end = (int)img->height - 1;
	if (ray->side_dist_x < ray->side_dist_y)
		vert->wall_x = data->map->player_pos.y + \
			ray->ray_dir.y * ray->hit_dist;
	else
		vert->wall_x = data->map->player_pos.x + \
			ray->ray_dir.x * ray->hit_dist;
	vert->wall_x -= floor(vert->wall_x);
	vert->tex_x = (int)(vert->wall_x * (double)(vert->texture->width));
	if (ray->side_dist_x < ray->side_dist_y && ray->ray_dir.x > 0)
		vert->tex_x = (int)vert->texture->width - vert->tex_x - 1;
	if (ray->side_dist_x >= ray->side_dist_y && ray->ray_dir.y < 0)
		vert->tex_x = (int)vert->texture->width - vert->tex_x - 1;
	vert->step = 1.0 * img->height / vert->line_height;
	vert->tex_pos = (vert->draw_start - (double)img->height / 2 + \
		(double)vert->line_height / 2) * vert->step;
}

void	draw_walls_textured(t_data *data, mlx_image_t *img)
{
	t_vertical	vert;
	int			x;

	x = 0;
	vert.line_thickness = (int)img->width / (int)data->ray_count;
	while (x < (int)data->ray_count)
	{
		init_vertical_data(&vert, img, data, &data->raycast[x]);
		draw_texture_vertical(img, &vert, x * vert.line_thickness);
		++x;
	}
}
