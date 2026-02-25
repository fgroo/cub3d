/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:13:34 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 14:34:19 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	digits(int n)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		sign;
	size_t	len;

	sign = 1;
	len = digits(n) + (n < 0);
	a = malloc(sizeof(*a) * (len + 1));
	if (!a)
		return (NULL);
	if (!n)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		sign = -sign;
	}
	a[len] = 0;
	while (n)
	{
		a[--len] = (char)(((n % 10) * sign) + '0');
		n /= 10;
	}
	return (a);
}
