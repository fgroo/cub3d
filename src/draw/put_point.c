/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:06:34 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/06 15:56:14 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "error.h"

#include <stdint.h>

void	put_point(mlx_image_t *img, t_vertex2i p, int size, uint32_t color)
{
	t_vertex2i	p1;
	t_vertex2i	p2;

	if (!img)
	{
		pr_error("put_point(): Image is NULL\n");
		return ;
	}
	if (size < 0)
		return ;
	p1.x = p.x - ((size - 1) / 2);
	p1.y = p.y - ((size - 1) / 2);
	p2.x = p1.x + size - 1;
	p2.y = p1.y + size - 1;
	put_square(img, p1, p2, color);
}
