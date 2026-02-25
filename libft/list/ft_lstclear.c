/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:38:47 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 17:11:32 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/** Clears all elements of a list.
 *
 *	Deletes and frees the given node and every successor of that node,
 *	using the function ’del’ and free(3).
 *	Finally, the pointer to the list must be set to NULL.
 *
 *	@param lst:	A pointer to the beginning of a list.
 *	@param del:	The function to delete the content of the node.
 *
 *	@returns:	None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
