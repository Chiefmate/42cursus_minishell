/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:40:09 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/16 14:40:09 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_strjoin_char(char *s, char c)
{
	char	*ret;
	size_t	s_len;

	if (!s && !c)
		return (0);
	else if (!s)
		return (ft_strdup(&c));
	s_len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (s_len + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, s_len + 1);
	ft_strlcpy(ret + s_len, &c, 2);
	free(s);
	return (ret);
}