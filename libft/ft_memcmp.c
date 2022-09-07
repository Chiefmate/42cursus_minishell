/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:56:54 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/04 21:12:21 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)buf1;
	p2 = (unsigned char *)buf2;
	while (count && *p1 == *p2)
	{
		count--;
		p1++;
		p2++;
	}
	if (!count)
		return (0);
	return (*p1 - *p2);
}
