/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:47:45 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/02 20:08:43 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "MLX42.h"
#include "error.h"

#include <stdint.h>

// 11111
// 11111
// 11111
// i = x + height*y
// y / height
// x % width
//

static void	_draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint8_t	*pixelstart;

	if (!image)
	{
		pr_error("put_pixel(): Image is NULL");
		return ;
	}
	if (x >= image->width)
		x %= image->width;
	if (y >= image->height)
		y %= image->height;
	pixelstart = &image->pixels[(y * image->width + x) * BPP];
	_draw_pixel(pixelstart, color);
}

void	draw_line(mlx_image_t *image, t_point *p1, t_point *p2)
{
	// Bresenham's Line Algorithm
	// or something like that
	// ...
}
