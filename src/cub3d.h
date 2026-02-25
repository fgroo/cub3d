/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:26:24 by rtwobie           #+#    #+#             */
/*   Updated: 2026/02/25 16:26:51 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
 * Texture files are saved in char *tex[] in this exact order:
 * char *tex[4] = { ./path-of-north-tex, ./path-of-south-tex,
 *					./path-of-east-tex, ./path-of-west-tex }
 */
typedef struct s_mapdata {
	char	*tex[4];
	int		floor_color;
	int		ceiling_color;
	char	*map[];
}	t_mapdata;

typedef struct s_data {
	t_mapdata	*map;
}	t_data;

#endif // !CUB3D_H
