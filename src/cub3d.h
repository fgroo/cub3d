/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:41:22 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/03 18:31:41 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
 * Texture files are saved in char *tex[] in this exact order:
 * char *tex[4] = { ./path-of-north-tex, ./path-of-south-tex,
 *					./path-of-east-tex, ./path-of-west-tex }
 */

typedef struct s_mapdata
{
	char	*tex[4];
	int		floor_color;
	int		ceiling_color;
	char	**map;
}	t_mapdata;

typedef struct s_data
{
	t_mapdata	*map;
}	t_data;

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
