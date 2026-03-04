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
	if (x >= image->width || y >= image->height)
	{
		pr_error("put_pixel(): Pixel is out of bounds");
		return ;
	}
	pixelstart = &image->pixels[(y * image->width + x) * BPP];
	_draw_pixel(pixelstart, color);
}

static void	_draw_line_h(mlx_image_t *image, t_point p1, t_point p2, uint32_t color)
{
	int	big_d;
	int	dx;
	int	dy;
	int	i;
	int dir;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dir = -1 + 2 * (dy >= 0);
	dy *= dir;
	big_d = 2 * dy - dx;
	i = 0;
	while (i < dx)
	{
		put_pixel(image, (uint32_t)(p1.x + i), (uint32_t)p1.y, color);
		if (big_d >= 0)
		{
			p1.y += dir;
			big_d -= 2 * dx;
		}
		big_d += 2 * dy;
		++i;
	}
}

static void	_draw_line_v(mlx_image_t *image, t_point p1, t_point p2, uint32_t color)
{
	int	big_d;
	int	dx;
	int	dy;
	int	i;
	int dir;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dir = -1 + 2 * (dx >= 0);
	dx *= dir;
	big_d = 2 * dx - dy;
	i = 0;
	while (i < dy)
	{
		put_pixel(image, (uint32_t)p1.x, (uint32_t)(p1.y + i), color);
		if (big_d >= 0)
		{
			p1.x += dir;
			big_d -= 2 * dy;
		}
		big_d += 2 * dx;
		++i;
	}
}

int ft_abs(int n)
{
	return (+n);
}

void put_line(mlx_image_t *image, t_point p1, t_point p2, uint32_t color)
{
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
	{
		if (p1.x > p2.x)
			_draw_line_h(image, p2, p1, color);
		_draw_line_h(image, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			_draw_line_v(image, p2, p1, color);
		_draw_line_v(image, p1, p2, color);
	}

}
