/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 18:50:53 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**	Copies n bytes of memory area src to memory area dest.
 *
 *	@param dest: 	The memory area to copy to.
 *	@param src:		The memory area to copy from.
 *	@param n:		The number of bytes to copy.
 *
 *	@returns:		A pointer to dest.
 */
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*usrc;
	unsigned char	*udest;

	usrc = (unsigned char *)src;
	udest = (unsigned char *)dest;
	while (n--)
		*udest++ = *usrc++;
	return (dest);
}
