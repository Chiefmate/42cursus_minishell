/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:51:41 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:41:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	idx = 0;
	if (d < s)
	{
		while (idx < n)
		{
			d[idx] = s[idx];
			idx++;
		}
	}
	else if (d > s)
	{
		idx = n;
		while (idx > 0)
		{
			idx--;
			d[idx] = s[idx];
		}
	}
	return (dst);
}
