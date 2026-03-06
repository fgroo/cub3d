/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:20:38 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/06 15:45:00 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "MLX42.h"
#include "error.h"

#include <stdint.h>

static void
	_draw_square(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color)
{
	int32_t	y;
	int32_t	x;

	p1 = clamp_vertex_to_img(p1, img->width, img->height);
	p2 = clamp_vertex_to_img(p2, img->width, img->height);
	y = p1.y;
	while (y < p2.y)
	{
		x = p1.x;
		while (x < p2.x)
		{
			put_pixel(img, (uint32_t)x, (uint32_t)y, color);
			++x;
		}
		++y;
	}
}

void
	put_square(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color)
{
	if (!img)
	{
		pr_error("put_square(): Image is NULL\n");
		return ;
	}
	if (p1.x > p2.x && p1.y > p2.y)
		_draw_square(img, p2, p1, color);
	else if (p1.x > p2.x)
	{
		_draw_square(img, (t_vertex2i){p2.x, p1.y},
			(t_vertex2i){p1.x, p2.y}, color);
	}
	else if (p1.y > p2.y)
	{
		_draw_square(img, (t_vertex2i){p1.x, p2.y},
			(t_vertex2i){p2.x, p1.y}, color);
	}
	_draw_square(img, p1, p2, color);
}
