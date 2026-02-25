/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:45:35 by rha-le            #+#    #+#             */
/*   Updated: 2025/01/23 00:15:04 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>

typedef enum e_type
{
	SIGN,
	UNSIGN
}	t_type;

typedef union u_type
{
	long			slong;
	uintptr_t		ptr;
}	t_uni;

int	ft_printf(const char *format, ...);

#endif
