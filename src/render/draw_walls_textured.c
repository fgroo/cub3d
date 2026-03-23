/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_textured.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:59:43 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/21 18:58:49 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "render_int.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

#include <stdint.h>
#include <stdio.h>

uint32_t	get_pixel_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t	color;
	uint32_t	i;

	i = (texture->width * (uint32_t)tex_y + (uint32_t)tex_x) * BPP;
	color = (uint32_t)texture->pixels[i++] << 24;
	color |= (uint32_t)texture->pixels[i++] << 16;
	color |= (uint32_t)texture->pixels[i++] << 8;
	color |= (uint32_t)texture->pixels[i];
	return (color);
}

static uint32_t	darken_color(uint32_t color, uint32_t luminence_in_percent)
{
	uint32_t darkened;
	uint32_t color_channel;

	if (luminence_in_percent > 100)
		luminence_in_percent = 100;
	color_channel = ((color >> 24) & 0xFF) * luminence_in_percent / 100;
	darkened = color_channel << 24;
	color_channel = ((color >> 16) & 0xFF) * luminence_in_percent / 100;
	darkened |= color_channel << 16;
	color_channel = ((color >> 8) & 0xFF) * luminence_in_percent / 100;
	darkened |= color_channel << 8;
	darkened |= 0xFF;
	return (darkened);
}

static void
	draw_texture_on_vertical(mlx_image_t *img, t_texmap *vert, int idx,
							char side)
{
	uint32_t	color;
	int			y;
	int			x;

	y = vert->draw_start;
	while (y < vert->draw_end)
	{
		vert->tex_y = (int)vert->tex_pos & (int)(vert->texture->height - 1);
		vert->tex_pos += vert->step;
		color = get_pixel_color(vert->texture, vert->tex_x, vert->tex_y);
		if (side == 'W' || side == 'N')
			color = darken_color(color, 80);
		x = 0;
		while (x < vert->line_thickness)
		{
			put_pixel(img, (uint32_t)(x + idx), (uint32_t)y, color);
			++x;
		}
		++y;
	}
}

void	draw_walls_textured(t_data *data, mlx_image_t *img)
{
	t_texmap	vert;
	int			x;

	x = 0;
	vert.line_thickness = (int)img->width / (int)data->ray_count;
	while (x < (int)data->ray_count)
	{
		map_texture_to_vertical(&vert, img, data->textures, &data->raycast[x]);
		draw_texture_on_vertical(img, &vert, x * vert.line_thickness,
						data->raycast[x].hit_side);
		++x;
	}
}
