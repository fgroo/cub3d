/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:29:42 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 12:36:19 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

#include "cub3d.h"

int	cleanup(t_data *data)
{
	if (!data)
		return (1);
	if (data->map)
		free_mapdata(data->map);
	if (data->img)
		free_images(data->mlx, data->img);
	if (data->raycast)
		free_raycast(data->raycast);
	if (data->textures)
		free_textures(data->textures);
	return (0);
}
