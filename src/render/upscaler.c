/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upscaler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:41:21 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/19 21:20:06 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "draw.h"
#include "cub3d.h"
#include "MLX42.h"

void	upscale(t_data *data)
{
	t_upscale	u;

	u.wstep = (float)data->img->game->width
		/ (float)data->img->game_upscld->width;
	u.hstep = (float)data->img->game->height
		/ (float)data->img->game_upscld->height;
	if (!data->img->game || !data->img->game_upscld
		|| !data->window_width || !data->window_height)
		return ;
	u.s = (uint32_t *)data->img->game->pixels;
	u.d = (uint32_t *)data->img->game_upscld->pixels;
	u.y = 0;
	while (u.y < data->img->game_upscld->height)
	{
		u.x = 0;
		while (u.x < data->img->game_upscld->width)
		{
			u.d[u.y * data->img->game_upscld->width + u.x]
				= u.s[(uint32_t)((float)u.y * u.hstep) * data->img->game->width
				+ (uint32_t)((float)u.x * u.wstep)];
			u.x++;
		}
		u.y++;
	}
}
