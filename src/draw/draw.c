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

#include "MLX42.h"

#include <stdint.h>

// 11111
// 11111
// 11111
// i = x + height*y
// y / height
// x % width
//
// NOTE: WHAT THE FUCK IS uint8_t *pixels AND HOW DO I USE IT????
//

void _draw_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	i;

	if (x >= image->width)
		x %= image->width;
	if (y >= image->height)
		y %= image->height;
	i = x + image->height * y;
	image->pixels[i] = (uint8_t)(color & 0x11111111);
}

void _draw_line()
{
	// Bresenham's Line Algorithm
	// or something like that
	// ...
}
