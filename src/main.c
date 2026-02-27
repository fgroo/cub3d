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
#include "error.h"
#include "parser.h"

#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || !argv || !argv[1] || !argv[1][0])
		return (pr_error("Please enter a .cub file\n"), 1);
	data.map = malloc(sizeof(*data.map));
	if (!data.map)
		return (pr_error("malloc\n"), 1);
	if (parser(data.map, argv[1]))
		return (1);
	(void)argc;
	(void)argv;
	return (0);
}
