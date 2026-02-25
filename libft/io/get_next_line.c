/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:01:01 by fgroo             #+#    #+#             */
/*   Updated: 2026/02/25 18:01:06 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_vars	v;
	t_tmp			tmp;

	tmp = (t_tmp){0, -1, NULL};
	if (read(fd, 0, 0) < 0)
		return (tmp.len = (fd >= 0 && (v.r[fd] = 0)), NULL);
	while (1)
	{
		if (v.p[fd] >= v.r[fd])
			(free(0), v.p[fd] = 0, v.r[fd] = read(fd, v.tmp[fd], BUFFER_SIZE));
		if (!v.r[fd])
			break ;
		v.buf[tmp.len++] = v.tmp[fd][v.p[fd]++];
		if (v.buf[tmp.len - 1] == '\n')
			break ;
	}
	if (v.r[fd] != -1 && tmp.len > 0)
	{
		tmp.res = malloc((size_t)tmp.len + 1);
		if (!tmp.res)
			return (NULL);
		while (++tmp.i < tmp.len && v.buf[tmp.i])
			(free(0), tmp.res[tmp.i] = v.buf[tmp.i], tmp.res[tmp.len] = 0);
	}
	return (tmp.res);
}
