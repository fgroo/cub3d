/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:28:55 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/18 23:22:37 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42.h"
#include "libft.h"

#include <stdlib.h>

static char	*join_free(char *a, char *b)
{
	char	*result;

	result = ft_strjoin(a, b);
	free(a);
	free(b);
	return (result);
}

void	display_debug(t_data *data)
{
	static mlx_image_t	*debug_txt = NULL;
	size_t				mid;
	char				*str;
	char				side[2];

	if (debug_txt)
		mlx_delete_image(data->mlx, debug_txt);
	mid = data->ray_count / 2;
	side[0] = data->raycast[mid].hit_side;
	side[1] = '\0';
	str = ft_strdup("pos:");
	str = join_free(str, ft_itoa((int)data->map->player_pos.x));
	str = join_free(str, ft_strdup(","));
	str = join_free(str, ft_itoa((int)data->map->player_pos.y));
	str = join_free(str, ft_strdup(" view:."));
	str = join_free(str, ft_itoa((int)(data->map->player_view.x * 100)));
	str = join_free(str, ft_strdup(",."));
	str = join_free(str, ft_itoa((int)(data->map->player_view.y * 100)));
	str = join_free(str, ft_strdup(" dist:"));
	str = join_free(str, ft_itoa((int)data->raycast[mid].hit_dist));
	str = join_free(str, ft_strdup(" side:"));
	str = join_free(str, ft_strdup(side));
	debug_txt = mlx_put_string(data->mlx, str, 1, 300);
	free(str);
}
