/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/05 19:31:18 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "error.h"
#include "parser.h"
#include "MLX42.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_loop_hook(data->mlx, render_minimap, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
//
// int	main(int argc, char *argv[])
// {
// 	t_data	data;
//
// 	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
// 		return (pr_error("Please enter a .cub file\n"), 1);
// 	data.map = ft_calloc(1, sizeof(*data.map));
// 	if (!data.map)
// 		return (pr_error("malloc\n"), 1);
// 	if (parser(data.map, argv[1]))
// 		return (1);
// 	if (init_mlx(&data))
// 		return (1);
// 	return (0);
// }

t_vertex2i p[8] = {
	{255,128},
	{255,255},
	{128,255},
	{0,255},
	{0,128},
	{0,0},
	{128,0},
	{255,0},
};

typedef struct s{
	mlx_t *mlx;
	mlx_image_t *img;
} t_mlx;

void spin_to_win(void *param)
{
	t_mlx *m = (t_mlx*)param;
	static int i = 0;
	if (i == 60 * 8)
	{
		mlx_delete_image(m->mlx, m->img);
		m->img = mlx_new_image(m->mlx, 256, 256);
		i = 0;
		mlx_image_to_window(m->mlx, m->img, 0, 0);
	}
	if (i % 60 == 0)
	{
		put_line(m->img, (t_vertex2i){128,128}, p[i/60], 0x00FF00FF);
	}
	++i;
}

int32_t	main(void)
{
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(720, 720, "MLX42", true);

    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* bg = mlx_new_image(mlx, 720, 720);

    // Set the channels of each pixel in our image to the maximum byte value of 255.
    // memset(bg->pixels, 255, bg->width * bg->height * BPP);

	// put_point(bg, (const t_vertex2i){50,50}, 7, 0xFF00FFFF);
	//
	// SQUARE TEST
	put_square(bg, (t_vertex2i){0,0}, (t_vertex2i){255,255}, 0xFF0000FF);
	put_square(bg, (t_vertex2i){191,191}, (t_vertex2i){0,0}, 0x00FF00FF);
	put_square(bg, (t_vertex2i){127,0}, (t_vertex2i){0,127}, 0x0000FFFF);
	put_square(bg, (t_vertex2i){0,63}, (t_vertex2i){63,0}, 0xFFFFFFFF);

	// put_square(bg, 0, 0, 0xFF0000FF, 50);

	mlx_image_to_window(mlx, bg, 0, 0);
    // Draw the image at coordinate (0, 0).

    // Run the main loop and terminate on quit.
	//
	// mlx_image_t *img = mlx_new_image(mlx, 256, 256);
	// t_mlx m = {mlx, img};
	// mlx_image_to_window(m.mlx, m.img, 0, 0);
	// mlx_loop_hook(mlx, spin_to_win, &m);
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}
