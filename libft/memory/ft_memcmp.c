/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:02:43 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 21:19:37 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Compares two objects.
 *
 *	@param s1:	The object to compare.
 *	@param s2:	The objext to compare against.
 *	@param n:	The amount of bytes to compare.
 *
 *	@returns:	0 if equal; A negative value if s1 is less than s2;
 *				A positive value if s1 is greater than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 == *us2 && n--)
	{
		++us1;
		++us2;
	}
	return ((int)(*us1 - *us2));
}
