/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:27:54 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 17:28:55 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Creates a new list resulting from applying a function to each element.
 *
 *	Iterates through the list ’lst’ and applies the function ’f’
 *	to the content of each node. A new list is created containing
 *	the results of the successive applications of the function ’f’.
 *	The ’del’ function is used to delete the content of a node if
 *	allocation or other operations fail.
 *
 *	@param lst:	A pointer to the beginning of a list.
 *	@param f:	The function to apply to each node's content.
 *	@param del:	The function to delete a node's content, if needed.
 *
 *	@returns:	A pointer to the new list, or NULL if memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = (f(lst->content));
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
