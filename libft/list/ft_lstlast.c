/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:32:25 by rha-le            #+#    #+#             */
/*   Updated: 2024/12/06 19:47:29 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Returns the last node of the list.
 *
 * @param lst:	The beginning of the list.
 *
 * @returns:	 A pointer to the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}
