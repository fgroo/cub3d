/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:54:14 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 12:32:47 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

void	free_textures(t_textures *textures)
{
	if (textures->north_wall)
		mlx_delete_texture(textures->north_wall);
	if (textures->south_wall)
		mlx_delete_texture(textures->south_wall);
	if (textures->east_wall)
		mlx_delete_texture(textures->east_wall);
	if (textures->west_wall)
		mlx_delete_texture(textures->west_wall);

	// if (textures->north_wall)
	// 	mlx_delete_xpm42(textures->north_wall);
	// if (textures->south_wall)
	// 	mlx_delete_xpm42(textures->south_wall);
	// if (textures->east_wall)
	// 	mlx_delete_xpm42(textures->east_wall);
	// if (textures->west_wall)
	// 	mlx_delete_xpm42(textures->west_wall);
	free(textures);
}
