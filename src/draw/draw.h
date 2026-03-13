/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:50 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/13 21:57:50 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "MLX42.h"

# include <stdint.h>

# ifndef BPP
#  define BPP 4
# endif // !BPP

typedef struct s_vertex2i
{
	int	x;
	int	y;
}		t_vertex2i;

int			clamp(int n, int lo, int hi);
t_vertex2i	clamp_vertex_to_img(t_vertex2i p, uint32_t width, uint32_t height);
void		put_pixel(mlx_image_t *img, uint32_t x,
				uint32_t y, uint32_t color);
void		put_line(mlx_image_t *img, t_vertex2i p1,
				t_vertex2i p2, uint32_t color);
void		put_point(mlx_image_t *img, const t_vertex2i p,
				int size, uint32_t color);
void		put_square(mlx_image_t *img, t_vertex2i p1,
				t_vertex2i p2, uint32_t color);

#endif
