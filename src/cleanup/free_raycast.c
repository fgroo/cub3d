/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwobie <student@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:54:14 by rtwobie           #+#    #+#             */
/*   Updated: 2026/03/18 12:01:12 by rtwobie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdlib.h>

void free_raycast(t_raycast *raycast)
{
	if (raycast->rays)
		free(raycast->rays);
	free(raycast);
}
