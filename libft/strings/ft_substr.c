/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:03:54 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 00:18:42 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	while (*s && start--)
		++s;
	size = ft_strlen(s);
	if (size < len)
		len = size;
	substr = malloc(sizeof(*substr) * (len + 1));
	if (!substr)
		return (NULL);
	if (!len)
		*substr = 0;
	else
		ft_strlcpy(substr, s, len + 1);
	return (substr);
}
