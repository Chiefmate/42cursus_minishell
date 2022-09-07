/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:53:17 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/04 20:57:11 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_memchr used
static size_t	ft_strnlen(char *str, size_t n)
{
	char	*part;

	part = ft_memchr(str, 0, n);
	if (!part)
		return (n);
	else
		return (part - str);
}

//	ft_strlen used
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;

	dest_len = ft_strnlen(dest, size);
	if (dest_len == size)
		return (dest_len + ft_strlen(src));
	return (ft_strlen(dest) \
			+ ft_strlcpy(dest + dest_len, src, size - dest_len));
}
