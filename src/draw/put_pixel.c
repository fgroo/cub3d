/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:47:45 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/05 17:06:23 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "error.h"
#include "libft.h"

#include <stdint.h>

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
		pr_error("put_pixel(): Image is NULL\n");
		return ;
	}
	if (x >= image->width || y >= image->height)
	{
		pr_error("put_pixel(): Pixel is out of bounds\n");
		return ;
	}
	pixelstart = &image->pixels[(y * image->width + x) * BPP];
	_draw_pixel(pixelstart, color);
}
