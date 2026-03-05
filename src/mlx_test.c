#include "draw.h"
#include "MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
// #define BPP sizeof(int32_t)

void put_square(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color, uint32_t size)
{
	uint32_t i = 0;
	uint32_t j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, i + x, j + y, color);
			++j;
		}
		++i;
	}
}

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
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);

    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* bg = mlx_new_image(mlx, 256, 256);

    // Set the channels of each pixel in our image to the maximum byte value of 255.
    memset(bg->pixels, 255, bg->width * bg->height * BPP);

	// put_square(bg, 0, 0, 0xFF0000FF, 50);

	mlx_image_to_window(mlx, bg, 0, 0);
    // Draw the image at coordinate (0, 0).

    // Run the main loop and terminate on quit.
	//
	mlx_image_t *img = mlx_new_image(mlx, 256, 256);
	t_mlx m = {mlx, img};
	mlx_image_to_window(m.mlx, m.img, 0, 0);
	mlx_loop_hook(mlx, spin_to_win, &m);
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}
