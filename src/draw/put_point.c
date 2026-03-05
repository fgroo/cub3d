/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:06:34 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/05 19:31:09 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdint.h>

void put_point(mlx_image_t *image, const t_vertex2i p, int size, uint32_t color)
{
	if (size < 0)
		return ;
	int x;
	int y;
	int start;
	int end;

	start = p.x - ((size - 1) / 2);
	end = start + size - 1;
	y = start;
	while (y < end)
	{
		x = start;
		while (x < end)
		{
			put_pixel(image, (uint32_t)x, (uint32_t)y, color);
			++x;
		}
		++y;
	}
}
