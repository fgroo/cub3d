/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:47:53 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/07 15:24:20 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Adds a node at the end of the list.
 *
 *	@param lst:	A pointer to the beginning of a list.
 *	@param node:	The node to be added to the list.
 *
 *	@returns:	None.
 */
void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (*lst == NULL)
		*lst = node;
	else
		ft_lstlast(*lst)->next = node;
}
