/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:15:41 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/06 15:37:22 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	clamp(int n, int lo, int hi)
{
	if (n < lo)
		return (lo);
	if (n > hi)
		return (hi);
	return (n);
}

t_vertex2i	clamp_vertex_to_img(t_vertex2i p, uint32_t width, uint32_t height)
{
	t_vertex2i	ret;

	ret.x = clamp(p.x, 0, (int)width - 1);
	ret.y = clamp(p.y, 0, (int)height - 1);
	return (ret);
}
