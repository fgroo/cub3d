/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:55:36 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 20:18:51 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Returns a pointer the first occurence of byte c in a memory area.
 *
 *	@param s: The memory area to search from.
 *	@param c: The byte to look for.
 *	@param n: The number of bytes to look into.
 *
 *	@returns: A pointer the matching byte; NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;

	us = (unsigned char *)s;
	while (n--)
		if (*us++ == (unsigned char)c)
			return (--us);
	return (NULL);
}
