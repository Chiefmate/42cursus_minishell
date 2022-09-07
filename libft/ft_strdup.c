/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:57:51 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:42:16 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_strlen used
char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	idx;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == (void *)0)
		return (ret);
	idx = 0;
	while (idx < ft_strlen(s))
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
