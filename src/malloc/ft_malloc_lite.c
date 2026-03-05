/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_lite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:23:29 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/02 19:09:53 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_malloc_lite.h"
#include "libft.h"

static size_t	align(size_t size)
{
	return ((size + (size_t)7) & ~(size_t)7);
}

void	*ft_malloc_lite(size_t size)
{
	t_chunkheader	*ptr;

	ptr = (t_chunkheader *)malloc(sizeof(t_chunkheader) + size);
	if (!ptr)
		return (NULL);
	ptr->size = size;
	ptr->is_free = 1;
	return ((void *)(ptr + 1));
}

void	ft_free(void *ptr)
{
	t_chunkheader	*header;

	if (!ptr)
		return ;
	header = (t_chunkheader *)ptr - 1;
	header->is_free = 1;
	free(header);
}

void	*ft_realloc_lite(void *ptr, size_t size)
{
	static size_t	power;
	t_chunkheader	*header;
	size_t			current_size;
	size_t			align_size;
	void			*new_ptr;

	if (!ptr)
		return (ft_malloc_lite(size));
	if (!size)
		return (ft_free(ptr), NULL);
	align_size = align(size);
	header = (t_chunkheader *)ptr - 1;
	current_size = header->size;
	if (align_size <= current_size)
		return (ptr);
	new_ptr = ft_malloc_lite(align_size * ++power);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, current_size);
	ft_free(ptr);
	return (new_ptr);
}
