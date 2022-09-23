/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:10:20 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 21:58:35 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

extern int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p2 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}