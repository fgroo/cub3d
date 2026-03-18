/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:59:52 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/18 12:32:57 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "render.h"
#include "draw.h"
#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>
#include <math.h>

static int	preinit_values(t_data *data, t_vector dir)
{
	data->raycast->map_x = (int)data->map->player_pos.x;
	data->raycast->map_y = (int)data->map->player_pos.y;
	data->raycast->side_dist_x = 1e30;
	data->raycast->side_dist_y = 1e30;
	data->raycast->delta_dist_x = 1e30;
	data->raycast->delta_dist_y = 1e30;
	data->raycast->step_x = 0;
	data->raycast->step_y = 0;
	if (dir.x == 0 && dir.y == 0)
		return (1);
	return (0);
}

static void	init_ray_values(t_data *data, t_vector dir)
{
	if (dir.x != 0)
		data->raycast->delta_dist_x = fabs(1.0 / dir.x);
	if (dir.y != 0)
		data->raycast->delta_dist_y = fabs(1.0 / dir.y);
	if (dir.x > 0)
		data->raycast->side_dist_x = (data->raycast->map_x + 1.0
				- data->map->player_pos.x) * data->raycast->delta_dist_x;
	else if (dir.x < 0)
		data->raycast->side_dist_x = (data->map->player_pos.x
				- data->raycast->map_x) * data->raycast->delta_dist_x;
	data->raycast->step_x = (dir.x > 0);
	if (dir.x < 0)
		data->raycast->step_x = -1;
	if (dir.y > 0)
		data->raycast->side_dist_y = (data->raycast->map_y + 1.0
				- data->map->player_pos.y) * data->raycast->delta_dist_y;
	else if (dir.y < 0)
		data->raycast->side_dist_y = (data->map->player_pos.y
				- data->raycast->map_y) * data->raycast->delta_dist_y;
	data->raycast->step_y = (dir.y > 0);
	if (dir.y < 0)
		data->raycast->step_y = -1;
}

static void	draw_single_ray(t_data *data, t_vector dir, double scale)
{
	t_vector	start;
	t_vector	end;

	start = data->map->player_pos;
	end = start;
	if (!preinit_values(data, dir) && (init_ray_values(data, dir), 1))
		end = raycast_wall_hit(data->map, data->raycast, dir);
	start.x *= TILESIZE * scale;
	start.y *= TILESIZE * scale;
	end.x *= TILESIZE * scale;
	end.y *= TILESIZE * scale;
	put_line(data->img->map_buf, (t_vertex2i){(int)start.x, (int)start.y},
		(t_vertex2i){(int)end.x, (int)end.y}, 0x00FF00FF);
	put_line(data->img->map_buf, (t_vertex2i){(int)start.x, (int)start.y},
		(t_vertex2i){(int)(data->map->cam_plane.x * 20) + (int)start.x, (int)(data->map->cam_plane.y * 20) + (int)start.y}, 0x0000FFFF);
}

static void	draw_rays_loop(t_data *data, double scale)
{
	t_vector	dir;
	double		camera_x;
	size_t		i;

	i = 0;
	while (i < data->raycast->ray_count)
	{
		camera_x = 2.0 * (double)i / (double)(data->raycast->ray_count - 1) - 1.0;
		dir.x = data->map->player_view.x + data->map->cam_plane.x * camera_x;
		dir.y = data->map->player_view.y + data->map->cam_plane.y * camera_x;
		draw_single_ray(data, dir, scale);
		data->raycast->rays[i] = data->raycast->hit_dist;
		i++;
	}
}

void	draw_rays(t_data *data)
{
	double		scale;

	scale = get_map_scale(data->map, data->img->map_buf);
	draw_rays_loop(data, scale);
}
