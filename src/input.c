/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:25:10 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/02 17:19:45 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

void	key_hook(mlx_key_data_t keycode, void *data __attribute__((unused)))
{
	if (keycode.key == MLX_KEY_ESCAPE)
		printf("close the window\n");
		// close_window(data);
	if (keycode.key == MLX_KEY_W)
		printf("Keypress: W\n");
	if (keycode.key == MLX_KEY_A)
		printf("Keypress: A\n");
	if (keycode.key == MLX_KEY_S)
		printf("Keypress: S\n");
	if (keycode.key == MLX_KEY_D)
		printf("Keypress: D\n");
	if (keycode.key == MLX_KEY_LEFT)
		printf("Keypress: LEFT\n");
	if (keycode.key == MLX_KEY_RIGHT)
		printf("Keypress: RIGHT\n");
}
