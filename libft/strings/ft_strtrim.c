/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:01:27 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 00:44:53 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*res;
	size_t	end;

	while (*s && ft_strchr(set, *s))
		++s;
	if (!*s)
		return (ft_strdup(""));
	end = ft_strlen(s);
	while (ft_strchr(set, s[end]))
		end--;
	res = ft_substr(s, 0, (end + 1));
	return (res);
}
