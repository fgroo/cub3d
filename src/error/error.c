/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:30:31 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/03 18:30:44 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

#include <unistd.h>

void	pr_error(const char *err)
{
	write(2, "Error\n", 6);
	if (err)
		write(2, err, ft_strlen(err));
}
