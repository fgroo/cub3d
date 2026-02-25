/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:49:19 by rha-le            #+#    #+#             */
/*   Updated: 2025/03/09 18:35:08 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Compares two strings.
 *
 *	@param s1:	The string to compare.
 *	@param s2:	The string to compare against.
 *
 *	@returns:	0 if equal; A negative value if s1 is less than s2;
 *				A positive value if s1 is greater than s2.
 */
int	ft_strcmp(const char s1[static 1], const char s2[static 1])
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 && *us2 && *us1 == *us2)
	{
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}
