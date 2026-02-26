/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:47:23 by fgroo             #+#    #+#             */
/*   Updated: 2026/02/26 16:08:57 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map = malloc(sizeof(t_mapdata));
	if (!data.map)
		return (pr_error("malloc\n"), 1);
	parser(data.map, argv);
	(void)argc;
	(void)argv;
	return (0);
}
