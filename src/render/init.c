/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:46:49 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/10 16:50:25 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "libft.h"
#include "render.h"

#include "cub3d.h"

int init_images(t_data *data)
{
	uint32_t	map_img_width;

	map_img_width = 320; // TODO: change values later
	data->img->map = mlx_new_image(data->mlx, map_img_width, map_img_width);
	if (!data->img->map)
		return (1);
	data->img->player = mlx_new_image(data->mlx, map_img_width, map_img_width);
	if (!data->img->player)
	{
		mlx_delete_image(data->mlx, data->img->map);
		return (1);
	}
	return (0);
}

