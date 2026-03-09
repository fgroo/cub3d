/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:43:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/09 18:01:29 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

static void	draw_tile(mlx_image_t *img, int x, int y, char tile)
{
	t_vertex2i	p1;
	t_vertex2i	p2;

	p1.x = x * TILESIZE * SCALE;
	p1.y = y * TILESIZE * SCALE;
	p2.x = (x + 1) * TILESIZE * SCALE - 1;
	p2.y = (y + 1) * TILESIZE * SCALE - 1;
	if (tile == '1')
		put_square(img, p1, p2, WALLTILE_COLOR);
	else if (tile == '0')
		put_square(img, p1, p2, FLOORTILE_COLOR);
}

void	render_2d_map(void *param)
{
	t_data		*data;
	int			y;
	int			x;

	data = (t_data *)param;
	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			draw_tile(data->img->map, x, y, data->map->map[y][x]);
			++x;
		}
		++y;
	}
	mlx_image_to_window(data->mlx, data->img->map, 0, 0);
}
