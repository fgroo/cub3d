/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:07:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 20:07:23 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**	Returns a pointer to the first occurrence of a character in a string.
 *
 *	@param s:	The string to search from.
 *	@param c:	The character to look for.
 *
 *	@returns:	A pointer to the matching character; NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
