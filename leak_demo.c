/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_demo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:48:56 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/23 14:48:56 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>

/*
** This is a simple leak demonstration that only initializes and
** terminates MLX42.
*/
int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(400, 400, "MLX42 Leak Demo", true);
	if (!mlx)
	{
		fprintf(stderr, "MLX Initialization failed: %s\n",
			mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	printf("MLX initialized successfully.\n");
	mlx_terminate(mlx);
	printf("MLX terminated.\n");
	return (EXIT_SUCCESS);
}
