/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:20:38 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/05 19:31:11 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "MLX42.h"
#include <stdint.h>

void	put_square(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color)
{
	t_vertex2i temp;

	if (p1.x > p2.x && p1.y > p2.y)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	else if (p1.x > p2.x)
	{
		temp.x = p1.x;
		p1.x = p2.x;
		p2.x = temp.x;
	}
	else if (p1.y > p2.y)
	{
		temp.y = p1.y;
		p1.y = p2.y;
		p2.y = temp.y;
	}
	int y = p1.y;
	while (y < p2.y)
	{
		int x = p1.x;
		while (x < p2.x)
		{
			put_pixel(img, (uint32_t)x, (uint32_t)y, color);
			++x;
		}
		++y;
	}
}
