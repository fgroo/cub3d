/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:14:47 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/24 22:29:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Inserts a node as head of list.
 *
 *  @param lst: The pointer to a list.
 *  @param new: The node to insert.
 *
 *  @returns:	None.
 */
void	ft_lstadd_front(t_list **lst, t_list *node)
{
	node->next = *lst;
	*lst = node;
}
