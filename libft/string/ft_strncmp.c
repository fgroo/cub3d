/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:47:45 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 19:25:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Compares the first n bytes of two strings.
 *
 *	@param s1:	The string to compare.
 *	@param s2:	The string to compare against.
 *	@param n:	The number of bytes to compare.
 *
 *	@returns:	0 if equal; A negative value if s1 is less than s2;
 *				A positive value if s1 is greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!n)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 && *us2 && *us1 == *us2 && --n)
	{
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}
