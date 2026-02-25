/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:18:07 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 14:51:58 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/** Removes one element from the list.
 *
 *	Takes as a parameter a node and frees the memory of the node’s content
 *	using the function ’del’ given as a parameter and free the node.
 *	The memory of ’next’ must not be freed.
 *
 *	@param lst:	The node to free.
 *	@param del:	The function used to delete the content.
 *
 *	@returns:	None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
