/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:11:29 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 21:07:50 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Fills n bytes of an memory area with byte c.
 *
 *	@param s: The pointer to the memory area.
 *	@param c: The byte to fill the memory area with.
 *	@param n: The number of bytes to fill.
 *
 *	@returns: A pointer to memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*us;

	us = (unsigned char *)s;
	while (n--)
		*us++ = (unsigned char)c;
	return (s);
}
