/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:18:46 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 15:27:32 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Iterates the list ’lst’ and applies the function ’f’
 *	on the content of each node.
 *
 *	@param lst:	A pointer to the beginning of a list.
 *	@param f:	The function used to iterate on the list.
 *
 *	@returns:	None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = temp->next;
		f(temp->content);
	}
}
