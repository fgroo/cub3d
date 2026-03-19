/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:59:52 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/19 21:38:03 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "render.h"
#include "draw.h"
#include "cub3d.h"
#include "libft.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h> // remove later

static int	preinit_values(t_data *data, t_raycast *ray)
{
	ray->map_x = (int)data->map->player_pos.x;
	ray->map_y = (int)data->map->player_pos.y;
	ray->side_dist_x = 1e30;
	ray->side_dist_y = 1e30;
	ray->delta_dist_x = 1e30;
	ray->delta_dist_y = 1e30;
	ray->step_x = 0;
	ray->step_y = 0;
	if (ray->ray_dir.x == 0 && ray->ray_dir.y == 0)
		return (1);
	return (0);
}

static void	init_ray_values(t_data *data, t_raycast *ray)
{
	if (ray->ray_dir.x != 0)
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir.x);
	if (ray->ray_dir.y != 0)
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir.y);
	if (ray->ray_dir.x > 0)
		ray->side_dist_x = (ray->map_x + 1.0
				- data->map->player_pos.x) * ray->delta_dist_x;
	else if (ray->ray_dir.x < 0)
		ray->side_dist_x = (data->map->player_pos.x
				- ray->map_x) * ray->delta_dist_x;
	ray->step_x = (ray->ray_dir.x > 0);
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	if (ray->ray_dir.y > 0)
		ray->side_dist_y = (ray->map_y + 1.0
				- data->map->player_pos.y) * ray->delta_dist_y;
	else if (ray->ray_dir.y < 0)
		ray->side_dist_y = (data->map->player_pos.y
				- ray->map_y) * ray->delta_dist_y;
	ray->step_y = (ray->ray_dir.y > 0);
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
}

static void	draw_single_ray(t_data *data, t_raycast *ray, double scale)
{
	t_vector	start;
	t_vector	end;

	start = data->map->player_pos;
	end = start;
	if (!preinit_values(data, ray) && (init_ray_values(data, ray), 1))
		end = raycast_wall_hit(data->map, ray);
	start.x *= TILESIZE * scale;
	start.y *= TILESIZE * scale;
	end.x *= TILESIZE * scale;
	end.y *= TILESIZE * scale;
	put_line(data->img->map_buf, (t_vertex2i){(int)start.x, (int)start.y},
		(t_vertex2i){(int)end.x, (int)end.y}, 0x00FF00FF);
	put_line(data->img->map_buf, (t_vertex2i){(int)start.x, (int)start.y},
		(t_vertex2i){(int)(data->map->cam_plane.x * 20) + (int)start.x,
		(int)(data->map->cam_plane.y * 20) + (int)start.y}, 0x0000FFFF);
}

static void	draw_rays_loop(t_data *data, double scale)
{
	double		camera_x;
	int			i;

	i = 0;
	while (i < (int)data->ray_count)
	{
		camera_x = 2.0 * i / (double)(data->ray_count - 1) - 1.0;
		data->raycast[i].ray_dir.x = data->map->player_view.x
			+ data->map->cam_plane.x * camera_x;
		data->raycast[i].ray_dir.y = data->map->player_view.y
			+ data->map->cam_plane.y * camera_x;
		draw_single_ray(data, &data->raycast[i], scale);
		i++;
	}
}

void	draw_rays(t_data *data)
{
	double		scale;

	scale = get_map_scale(data->map, data->img->map_buf);
	draw_rays_loop(data, scale);
}
