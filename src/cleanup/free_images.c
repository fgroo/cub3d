/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:41:46 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/20 23:44:55 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

#include "MLX42.h"
#include "cub3d.h"

#include <stdlib.h>

void	free_images(mlx_t *mlx, t_image *image)
{
	if (image->map_buf)
		mlx_delete_image(mlx, image->map_buf);
	if (image->map)
		mlx_delete_image(mlx, image->map);
	if (image->game_buf)
		mlx_delete_image(mlx, image->game_buf);
	if (image->game)
		mlx_delete_image(mlx, image->game);
	if (image->game_upscld)
		mlx_delete_image(mlx, image->game_upscld);
	free(image);
}
