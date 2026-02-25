/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:20:18 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 22:25:48 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Copies n bytes from memory area s2 to memory area s1.
 *
 *	@param s1:	The memory area to copy to.
 *	@param s2:	The memory area to copy from.
 *	@param n:	The amount of bytes to copy.
 *
 *	@returns:	A pointer to s1.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*usrc;
	unsigned char	*udest;

	usrc = (unsigned char *)src;
	udest = (unsigned char *)dest;
	if (src > dest)
		while (n--)
			*udest++ = *usrc++;
	else if (src < dest)
		while (n--)
			*(udest + n) = *(usrc + n);
	return (dest);
}
