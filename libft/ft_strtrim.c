/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:20 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/07 04:52:55 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_strlen, ft_strchr, ft_strdup, ft_strlcpy used
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]))
	{
		if (end == 0)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}
