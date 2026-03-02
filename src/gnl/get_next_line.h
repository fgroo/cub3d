/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:11:07 by fgroo             #+#    #+#             */
/*   Updated: 2025/11/25 16:08:50 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	char	buf[100000];
	char	tmp[1024][100000];
	ssize_t	p[1024];
	ssize_t	r[1024];
}	t_vars;

typedef struct s_tmp
{
	ssize_t	len;
	ssize_t	i;
	char	*res;
}	t_tmp;

char	*get_next_line(int fd);

#endif

