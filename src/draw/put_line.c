/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:03:48 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/13 21:51:09 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "error.h"
#include "libft.h"

#include <stdint.h>

static void	_draw_line_h(mlx_image_t *img, t_vertex2i p1,
		t_vertex2i p2, uint32_t color)
{
	int	big_d;
	int	dx;
	int	dy;
	int	i;
	int	dir;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dir = -1 + 2 * (dy >= 0);
	dy *= dir;
	big_d = 2 * dy - dx;
	i = 0;
	while (i < dx)
	{
		put_pixel(img, (uint32_t)(p1.x + i), (uint32_t)p1.y, color);
		if (big_d >= 0)
		{
			p1.y += dir;
			big_d -= 2 * dx;
		}
		big_d += 2 * dy;
		++i;
	}
}

static void	_draw_line_v(mlx_image_t *img, t_vertex2i p1,
		t_vertex2i p2, uint32_t color)
{
	int	big_d;
	int	dx;
	int	dy;
	int	i;
	int	dir;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	dir = -1 + 2 * (dx >= 0);
	dx *= dir;
	big_d = 2 * dx - dy;
	i = 0;
	while (i < dy)
	{
		put_pixel(img, (uint32_t)p1.x, (uint32_t)(p1.y + i), color);
		if (big_d >= 0)
		{
			p1.x += dir;
			big_d -= 2 * dy;
		}
		big_d += 2 * dx;
		++i;
	}
}

void	put_line(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color)
{
	if (!img)
	{
		pr_error("put_line(): Image is NULL\n");
		return ;
	}
	p1 = clamp_vertex_to_img(p1, img->width, img->height);
	p2 = clamp_vertex_to_img(p2, img->width, img->height);
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
	{
		if (p1.x > p2.x)
			_draw_line_h(img, p2, p1, color);
		_draw_line_h(img, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			_draw_line_v(img, p2, p1, color);
		_draw_line_v(img, p1, p2, color);
	}
}
