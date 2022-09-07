/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:00:26 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 21:28:42 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*parse_ret(char is_neg, char *org_ret)
{
	char	*ret;
	size_t	size;
	size_t	i;

	size = 0;
	while (*(org_ret + size) != -1)
		size++;
	if (is_neg)
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	i = 0;
	if (is_neg)
	{
		ret[i++] = '-';
		size--;
	}
	while (size > 0)
	{	
		ret[i++] = '0' + org_ret[size - 1];
		size--;
	}
	ret[i] = '\0';
	return (ret);
}

static void	make_ret(int n, char is_neg, char *org_ret)
{
	size_t	i;
	char	not_last;

	not_last = 1;
	i = 0;
	while (n || not_last)
	{
		org_ret[i++] = (1 - 2 * is_neg) * (char)(n % 10);
		not_last = 0;
		if ((-100 < n && n < -9) || (9 < n && n < 100))
			not_last = 1;
		n /= 10;
	}
	return ;
}

//  ft_isdigit used
char	*ft_itoa(int n)
{
	char	org_ret[12];
	char	*ret;
	char	is_neg;
	int		i;

	i = -1;
	while (++i < 12)
		org_ret[i] = -1;
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	make_ret(n, is_neg, org_ret);
	ret = parse_ret(is_neg, org_ret);
	return (ret);
}
