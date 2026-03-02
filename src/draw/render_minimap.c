/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:43:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/02 20:07:11 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"

void render_minimap(void *param)
{
	t_data *data;

	data = (t_data*)param;
	static mlx_image_t	*image_buf;

	image_buf = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	_draw_pixel(image_buf, 250, 250, 0xFFFFFFFF);
	mlx_image_to_window(data->mlx, image_buf, 0, 0);
	mlx_delete_image(data->mlx, image_buf);
}
