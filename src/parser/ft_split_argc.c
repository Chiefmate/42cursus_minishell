/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:44:09 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/16 14:44:09 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*free_so_far_done(char **strarr, int str_idx)
{
	int	i;

	i = 0;
	while (i < str_idx)
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
	return (NULL);
}

static int	get_word_cnt(char const *str, char c)
{
	size_t	cnt;
	int		chker;

	cnt = 0;
	chker = 1;
	while (*str != '\0' && *str == c)
		str++;
	while (*str)
	{
		if (chker == 1 && *str != c)
		{
			cnt++;
			chker = 0;
		}
		if (*str == c)
			chker = 1;
		str++;
	}
	return (cnt);
}

set_worddup

char	**ft_split_argc(char const *s, char c, int *argc)
{
	char	**ret;

	ret = NULL;
	if (!s)
		return (NULL);
	*argc = get_word_cnt(s, c);
	ret = (char **)malloc(sizeof(char *) * (*argc + 1));
	if (!ret)
		return (NULL);
	ret = set_worddup(s, c, ret);
	return (ret);
}