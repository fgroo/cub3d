/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:41:46 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/09 17:44:54 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

#include "MLX42.h"
#include "cub3d.h"

#include <stdlib.h>

void	free_images(mlx_t *mlx, t_image *image)
{
	if (image->player)
		mlx_delete_image(mlx, image->player);
	if (image->map)
		mlx_delete_image(mlx, image->map);
	free(image);
}
