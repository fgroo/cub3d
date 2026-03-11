/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:43:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/10 17:06:13 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"

static int	get_map_width(t_mapdata *map)
{
	int	i;
	int	width;
	int	ret;

	if (!map || !map->map ||!map->map[0])
		return (0);
	i = 0;
	ret = 0;
	while (map->map[i])
	{
		width = (int)ft_strlen(map->map[i]);
		if (width > ret)
			ret = width;
		++i;
	}
	return (ret);
}

static void	draw_tile(mlx_image_t *img, t_vector p, int map_width, char tile)
{
	t_vertex2i	p1;
	t_vertex2i	p2;
	double		scale;

	scale = (double)img->width / ((double)map_width * TILESIZE);
	p1.x = (int)(p.x * TILESIZE * scale);
	p1.y = (int)(p.y * TILESIZE * scale);
	p2.x = (int)((p.x + 1) * TILESIZE * scale) - 1;
	p2.y = (int)((p.y + 1) * TILESIZE * scale) - 1;
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
			draw_tile(data->img->map, (t_vector){x, y},
					get_map_width(data->map), data->map->map[y][x]);
			++x;
		}
		++y;
	}
	mlx_image_to_window(data->mlx, data->img->map, 0, 0);
}
