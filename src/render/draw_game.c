/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:39:05 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 22:08:05 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

#include <stdint.h>

static void	draw_background(t_data *data, mlx_image_t *img)
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

static uint32_t	get_wall_side_color(t_raycast *ray)
{
	if (ray->hit_side == 'N')
		return (RGB_GREEN);
	else if (ray->hit_side == 'E')
		return (RGB_GREY_DIM);
	else if (ray->hit_side == 'S')
		return (RGB_GREY);
	else if (ray->hit_side == 'W')
		return (RGB_GREEN_DIM);
	return (RGB_MAGENTA);
}

static void	draw_color_vertical(t_raycast *ray, mlx_image_t *img,
							int line_thickness,
							int idx)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	i;

	line_height = (int)(img->height / ray->hit_dist);
	draw_start = -line_height / 2 + (int)img->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + (int)img->height / 2;
	if (draw_end >= (int)img->height)
		draw_end = (int)img->height - 1;
	i = 0;
	while (i < line_thickness)
	{
		put_line(img, (t_vertex2i){idx + i, draw_start},
			(t_vertex2i){idx + i, draw_end}, get_wall_side_color(ray));
		++i;
	}
}

void	draw_walls_untextured(t_data *data, mlx_image_t *img)
{
	int	line_thickness;
	int	i;

	line_thickness = (int)img->width / (int)data->ray_count;
	i = 0;
	while (i < (int)data->ray_count)
	{
		draw_color_vertical(&data->raycast[i], img,
			line_thickness, i * line_thickness);
		++i;
	}
}

void	draw_game_img(t_data *data, mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * BPP);
	draw_background(data, img);
	// draw_walls_untextured(data, img);
	draw_walls_textured(data, img);
}
