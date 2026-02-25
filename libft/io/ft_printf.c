/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:54:33 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/25 17:19:19 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define DEC "0123456789"
#define HEX_L "0123456789abcdef"
#define HEX_U "0123456789ABCDEF"

void	putnb(t_uni nb, char *base, int *count, t_type type)
{
	long			nbase;
	long			s_nb;
	unsigned long	u_nb;

	nbase = 0;
	while (base[nbase])
		nbase++;
	if (type == SIGN)
	{
		s_nb = nb.slong;
		if (s_nb < 0)
			(free(NULL), *count += ft_putchar_fd('-', 1), s_nb = -s_nb);
		if (s_nb >= nbase)
			putnb((t_uni){.slong = s_nb / nbase}, base, count, SIGN);
		*count += ft_putchar_fd((unsigned char)base[s_nb % nbase], 1);
	}
	if (type == UNSIGN)
	{
		u_nb = nb.ptr;
		if (u_nb >= (unsigned)nbase)
			putnb((t_uni){.ptr = u_nb / (unsigned)nbase}, base, count, UNSIGN);
		*count += ft_putchar_fd((unsigned char)base[u_nb % (unsigned)nbase], 1);
	}
}

void	is_ptr_valid(void *p, int *count)
{
	if (p == NULL)
		*count += ft_putstr_fd("(nil)", 1);
	else
	{
		*count += ft_putstr_fd("0x", 1);
		putnb((t_uni){.ptr = (uintptr_t)p}, HEX_L, count, UNSIGN);
	}
}

void	ft_print_arg(va_list args, char arg, int *count)
{
	if (arg == 'i' || arg == 'd')
		putnb((t_uni){.slong = va_arg(args, int)}, DEC, count, SIGN);
	else if (arg == 'u')
		putnb((t_uni){.slong = va_arg(args, unsigned int)}, DEC, count, SIGN);
	else if (arg == 'x')
		putnb((t_uni){.slong = va_arg(args, unsigned int)}, HEX_L, count, SIGN);
	else if (arg == 'X')
		putnb((t_uni){.slong = va_arg(args, unsigned int)}, HEX_U, count, SIGN);
	else if (arg == 'c')
		*count += ft_putchar_fd((unsigned char)va_arg(args, int), 1);
	else if (arg == 's')
		*count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (arg == 'p')
		is_ptr_valid(va_arg(args, void *), count);
	else if (arg == '%')
		*count += ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += (int)write(1, &format[i++], 1);
		else if (format[i] == '%')
		{
			i++;
			ft_print_arg(args, format[i++], &count);
		}
	}
	va_end(args);
	return (count);
}
