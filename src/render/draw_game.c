/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:39:05 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/17 17:00:31 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

#include <stdint.h>

static void draw_background(t_data *data, mlx_image_t *img)
{
	put_square(img, 
			(t_vertex2i){0, 0}, 
			(t_vertex2i){(int)img->width, (int)img->height / 2},
			data->map->ceiling_color);
	put_square(img, 
			(t_vertex2i){0, (int)img->height / 2}, 
			(t_vertex2i){(int)img->width, (int)img->height}, 
			data->map->floor_color);
}

static void	draw_vertical(t_data *data, mlx_image_t *img, int line_thickness, int idx)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	i;

	line_height = (int)(img->height / data->raycast->hit_dist);
	draw_start = -line_height / 2 + (int)img->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + (int)img->height / 2;
	if (draw_end >= (int)img->height)
		draw_end = (int)img->height - 1;
	i = 0;
	while(i < line_thickness)
	{
		put_line(img, (t_vertex2i){idx + i, draw_start}, (t_vertex2i){idx + i, draw_end}, 0x00FFFFFF);
		++i;
	}
}

static void	draw_walls_untextured(t_data *data, mlx_image_t *img)
{
	int	line_thickness;
	int	i;

	line_thickness = (int)img->width / RAY_COUNT;
	i = 0;
	while(i < (int)img->width)
	{
		draw_vertical(data, img, line_thickness, i);
		i += line_thickness;
	}
}

void	draw_game_img(t_data *data, mlx_image_t *img)
{
	draw_background(data, img);
	draw_walls_untextured(data, img);
}
