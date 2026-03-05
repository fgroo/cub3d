/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:03:48 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/05 19:31:01 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "libft.h"

#include <stdint.h>

static void	_draw_line_h(mlx_image_t *image, t_vertex2i p1, t_vertex2i p2, uint32_t color)
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

static void	_draw_line_v(mlx_image_t *image, t_vertex2i p1, t_vertex2i p2, uint32_t color)
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

// TODO: clamp if out of bounds
void put_line(mlx_image_t *image, t_vertex2i p1, t_vertex2i p2, uint32_t color)
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
