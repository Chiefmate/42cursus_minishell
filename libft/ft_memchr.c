/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:56:36 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/04 21:06:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*ret;

	ret = (unsigned char *)buf;
	while (count && *ret != (unsigned char)c)
	{
		count--;
		ret++;
	}
	if (!count)
		return (0);
	return ((void *)ret);
}
