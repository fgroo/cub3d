/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:59:17 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/04 19:04:33 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		count += (int)write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr_fd((n / 10), fd);
	n = (n % 10) + '0';
	count += (int)write(fd, &n, 1);
	return (count);
}
