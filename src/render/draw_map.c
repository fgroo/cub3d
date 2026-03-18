/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:43:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/17 14:55:31 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"

static void	draw_tile(mlx_image_t *img, t_vertex2i p, double scale, char tile)
{
	t_vertex2i	p1;
	t_vertex2i	p2;

	p1.x = (int)(p.x * TILESIZE * scale);
	p1.y = (int)(p.y * TILESIZE * scale);
	p2.x = (int)((p.x + 1) * TILESIZE * scale) - 1;
	p2.y = (int)((p.y + 1) * TILESIZE * scale) - 1;
	if (tile == '1')
		put_square(img, p1, p2, WALLTILE_COLOR);
	else if (tile == '0')
		put_square(img, p1, p2, FLOORTILE_COLOR);
}

void	draw_map(t_mapdata *map, mlx_image_t *img, double scale)
{
	int			y;
	int			x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			draw_tile(img, (t_vertex2i){x, y}, scale, map->map[y][x]);
			++x;
		}
		++y;
	}
}

void	draw_map_img(t_mapdata *map, mlx_image_t *img)
{
	double	scale;

	scale = get_map_scale(map, img);
	ft_memset(img->pixels, 0, img->width * img->height * BPP);
	draw_map(map, img, scale);
	draw_player(map, img, scale);
}
