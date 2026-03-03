#include "MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

void put_square(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color, uint32_t size)
{
	uint32_t i = 0;
	uint32_t j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, i + x, j + y, color);
			++j;
		}
		++i;
	}
}

int32_t	main(void)
{
    // Init mlx with a canvas size of 256x256 and the ability to resize the window.
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);

    if (!mlx) exit(EXIT_FAILURE);

    // Create a 128x128 image.
    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    // Set the channels of each pixel in our image to the maximum byte value of 255.
    // memset(img->pixels, 255, img->width * img->height * BPP);
	// put_square(img, 0, 0, 0xFF0000FF, 50);
	uint32_t *pixel = (uint32_t*)img->pixels;
	printf("pixel: 0x%x\n", *pixel);
	*pixel = 0xFF00FF00;

	// mlx_put_pixel(img, 0, 0, 0xFF00FF00);

	printf("pixel: 0x%x\n", *pixel);
    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}
