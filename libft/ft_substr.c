/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:58:31 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/11 11:25:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	strlen, strdup used
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	idx;
	size_t			m_size;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	m_size = len;
	if (ft_strlen(s) - start < len)
		m_size = ft_strlen(s) - start;
	ret = (char *)malloc(sizeof(char) * (m_size + 1));
	if (!ret)
		return (0);
	idx = start;
	while (idx - start < len && s[idx])
	{
		ret[idx - start] = s[idx];
		idx++;
	}
	ret[idx - start] = '\0';
	return (ret);
}
