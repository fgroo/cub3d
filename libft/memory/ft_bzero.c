/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:55:05 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 18:37:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Erases the data in the n bytes of a memory location.
 *
 *	@param s: The pointer where to start from.
 *	@param n: The number of bytes to erase.
 *
 *	@returns: None.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*us;

	us = (unsigned char *)s;
	while (n--)
		*us++ = 0;
}
