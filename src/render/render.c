/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/17 14:59:59 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "input.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"

double	get_map_scale(t_mapdata *map, mlx_image_t *img)
{
	if (map->width > map->height)
		return ((double)img->width / ((double)map->width * TILESIZE));
	return ((double)img->height / ((double)map->height * TILESIZE));
}

// TODO: add draw_rays()
void	draw_map_img(t_mapdata *map, mlx_image_t *img)
{
	double	scale;

	scale = get_map_scale(map, img);
	ft_memset(img->pixels, 0, img->width * img->height * BPP);
	draw_map(map, img, scale);
	draw_player(map, img, scale);
}

// NOTE: This function will be called each frame
void	render_map(void *param)
{
	t_data		*data;
	mlx_image_t	*tmp;

	data = (t_data *)param;
	draw_map_img(data->map, data->img->map_buf);
	draw_rays(data);
	tmp = data->img->map;
	data->img->map = data->img->map_buf;
	data->img->map_buf = tmp;
}

// TODO: change values of width and height later
int	init_images(t_data *data)
{
	uint32_t	width;
	uint32_t	height;

	width = 320;
	height = 320;
	data->img->map = mlx_new_image(data->mlx, width, height);
	if (!data->img->map)
		return (1);
	data->img->map_buf = mlx_new_image(data->mlx, width, height);
	if (!data->img->map)
	{
		mlx_delete_image(data->mlx, data->img->map);
		return (1);
	}
	mlx_image_to_window(data->mlx, data->img->map, 0, 0);
	return (0);
}
