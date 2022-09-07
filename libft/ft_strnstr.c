/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:35 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/07 01:03:22 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_strlen used
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		while (*(big + i) == *(little + i) && i < len)
		{
			i++;
			if (!(*(little + i)))
				return ((char *) big);
		}
		len--;
		big++;
	}
	return (NULL);
}
