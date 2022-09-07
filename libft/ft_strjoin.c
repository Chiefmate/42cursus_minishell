/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:58:56 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 21:00:03 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_strlen, ft_strdup used
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	idx;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return ((void *)0);
	idx = -1;
	while (++idx < ft_strlen(s1))
		ret[idx] = s1[idx];
	while (idx < ft_strlen(s1) + ft_strlen(s2))
	{
		ret[idx] = s2[idx - ft_strlen(s1)];
		idx++;
	}	
	ret[idx] = '\0';
	return (ret);
}
