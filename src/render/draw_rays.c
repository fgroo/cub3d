/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:59:52 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/12 16:13:59 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"

typedef	struct s_out
{
	int		player_pos_x;
	int		player_pos_y;
	int		player_view_x;
	int		player_view_y;
}			t_out;

static void dda(t_out in)
{
	double  m;
	double	dx;
	double	dy;
	int		steps;
	
	
}
static t_out	double_to_int(t_vector player_pos, t_vector	player_view)
{
	t_out	out;
	
	
	return (out);
}

// if (!(double x or y << 1)) positive

int draw_rays(t_data *data)
{
	dda(double_to_int(data->map->player_pos, data->map->player_view));
}
