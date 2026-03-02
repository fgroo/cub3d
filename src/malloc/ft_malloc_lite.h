/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_lite.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:19:02 by fgroo             #+#    #+#             */
/*   Updated: 2026/03/02 20:20:44 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_LITE_H
# define FT_MALLOC_LITE_H

# include <stddef.h>

typedef struct s_chunkheader
{
	size_t	size;
	int		is_free;
	int		padding;
}	t_chunkheader;

void	*ft_malloc_lite(size_t size);
void	ft_free(void *ptr);
void	*ft_realloc_lite(void *ptr, size_t size);

#endif