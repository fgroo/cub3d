/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:37:41 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 22:40:10 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/** Locates the first occurence of string little in string big.
 *
 *	@param big:		String to look into.
 *	@param little:	String to search for.
 *	@param len:		Amount of bytes of big to look into.
 *
 *	@returns:		Pointer to first occurence of [little];
 *					[big] if [little] is empty; NULL if [little] is not found
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && i + j < len)
			++j;
		if (little[j] == '\0')
			return ((char *)(big + i));
		++i;
	}
	return (NULL);
}
