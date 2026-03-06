/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:22 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/02 17:18:17 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 720

# include "MLX42.h"

/*
 * Texture files are saved in char *tex[] in this exact order:
 * char *tex[4] = { ./path-of-north-tex, ./path-of-south-tex,
 *					./path-of-east-tex, ./path-of-west-tex }
 */
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_mapdata
{
	char	*tex[4];
	int		floor_color;
	int		ceiling_color;
	char	spawn_orientation;
	t_point	spawn_coordinates;
	char	**map;
}	t_mapdata;

typedef struct s_data {
	mlx_t		*mlx;
	t_mapdata	*map;
}	t_data;

#include "MLX42.h"
void	key_hook(mlx_key_data_t keycode, void *data);

/*
----------------------------PARSING----------------------------
*/
// # include "parser.h"

// int parser(t_mapdata *map, char *argv[]);
// int validate_format(int fd, t_mapdata *mapdata);

/*
----------------------------ERROR----------------------------
*/
// # include "error.h"

#endif // !CUB3D_H
