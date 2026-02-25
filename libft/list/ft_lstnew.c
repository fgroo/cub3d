/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:09:53 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/13 23:48:42 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/** Creates a new node.
 *
 *  Allocates (with malloc(3)) and returns a new node.
 *  The member variable ’content’ is initialized with
 *  the value of the parameter ’content’. The variable
 *  ’next’ is initialized to NULL.
 *
 *  @param content:	The value to be initialized when the list gets created.
 *
 *  @returns:		A pointer to the list.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
