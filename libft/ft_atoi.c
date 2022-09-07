/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:58 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/15 12:29:22 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int n)
{
	if (n == ' ' || n == '\f' || n == '\n' || \
	n == '\r' || n == '\t' || n == '\v')
		return (1);
	return (0);
}

static long long	make_n(const char *s, char is_neg)
{
	long long	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		n = 10 * n + (*s++ - '0');
		if (n >= 100000000000000000 && !is_neg && (*s > LONG_MAX % 10))
			return (-1);
		else if (n >= 100000000000000000 && is_neg \
				&& (*s > ((-1) * (LONG_MIN % 10))))
			return (0);
	}
	if (is_neg)
		return (-n);
	return (n);
}

//  ft_isdigit() used, limits.h included for LONG_MAX, LONG_MIN
int	ft_atoi(const char *s)
{
	char		is_neg;

	is_neg = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		is_neg = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	return ((int)make_n(s, is_neg));
}
