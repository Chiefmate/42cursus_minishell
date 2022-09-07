/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:31 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/04 18:36:39 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_strlen used
char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (void *)0;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
		{
			ret = (char *)s;
			break ;
		}
		s++;
	}
	return (ret);
}
