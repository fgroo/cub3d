/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/11 18:43:30 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "MLX42.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"

// NOTE: This function will be called each frame

// TODO: add draw_rays() and draw_player_orientatio();
void	draw_map_img(t_mapdata *map, mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * BPP);
	draw_map(map, img);
	draw_player(map, img);
}

void	render_map(void *param)
{
	t_data		*data;
	mlx_image_t	*tmp;

	data = (t_data *)param;
	draw_map_img(data->map, data->img->map_buf);
	tmp = data->img->map;
	data->img->map = data->img->map_buf;
	data->img->map_buf = tmp;
}

// TODO: change values of width and height later
int init_images(t_data *data)
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

