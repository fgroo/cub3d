/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:31:52 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 00:33:54 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*i;

	dest = malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = dest;
	while (*src)
		*i++ = *src++;
	*i = 0;
	return (dest);
}
