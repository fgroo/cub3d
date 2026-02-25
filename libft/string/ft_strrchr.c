/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:07:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 21:01:56 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**	Returns a pointer to the last occurrence of a character in a string.
 *
 *	@param s:	The string to search from.
 *	@param c:	The character to look for.
 *
 *	@returns:	A pointer to the matching character; NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (!s)
		return (0);
	last = NULL;
	while (*s)
		if (*s++ == (char)c)
			last = (char *)(s - 1);
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}
