/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:26:04 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/17 18:01:56 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "draw.h"
#include "cub3d.h"
#include "libft.h"

void	dda(t_vector start, t_vector end, mlx_image_t *img)
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;

	dx = (int)(end.x - start.x);
	dy = (int)(end.y - start.y);
	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	if (steps == 0)
		return ;
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	while (steps--)
	{
		if (start.x >= 0 && start.y >= 0 && start.x < (double)img->width
			&& start.y < (double)img->height)
			put_pixel(img, (uint32_t)start.x, (uint32_t)start.y, 0x00FF00FF);
		start.x += x_inc;
		start.y += y_inc;
	}
}

int	is_wall(t_mapdata *map, int x, int y, t_raycast *ray)
{
	char	*row;

	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return (1);
	row = map->map[y];
	if (!row || x >= (int)ft_strlen(row))
		return (1);
	if (row[x] == '1' || row[x] == ' ')
	{
		ray->hit_side_x = ray->step_x;
		ray->hit_side_y = ray->step_y;
		return (1);
	}
	return (0); // saving the wall side where raycaster hits
}

t_vector	raycast_wall_hit(t_mapdata *map, t_raycast *ray, t_vector dir)
{
	int	i;

	i = 0;
	ray->hit_side_x = 0;
	ray->hit_side_y = 0;
	while (i++ < map->width * map->height)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->hit_dist = ray->side_dist_x - ray->delta_dist_x;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->hit_dist = ray->side_dist_y - ray->delta_dist_y;
		}
		if (is_wall(map, ray->map_x, ray->map_y, ray))
			break ;
	}
	ray->hit.x = map->player_pos.x + dir.x * ray->hit_dist;
	ray->hit.y = map->player_pos.y + dir.y * ray->hit_dist;
	return (ray->hit);
}
