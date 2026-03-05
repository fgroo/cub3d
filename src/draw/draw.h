/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:50 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/05 19:30:59 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "MLX42.h"
# include "cub3d.h"

# include <stdint.h>

# ifndef BPP
#  define BPP sizeof(uint32_t)
# endif // !BPP

typedef struct s_vertex2i {
	int	x;
	int	y;
} t_vertex2i;

void	put_pixel(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t color);
void	put_line(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color);
void	put_point(mlx_image_t *img, const t_vertex2i p, int size, uint32_t color);
void	put_square(mlx_image_t *img, t_vertex2i p1, t_vertex2i p2, uint32_t color);
void	render_minimap(void *param);

#endif
