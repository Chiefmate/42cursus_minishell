/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:57:54 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/28 16:31:55 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_have_n(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strncmp(str, "-n", 2))
		return (0);
	++str;
	while (*str == 'n')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

static int	check_option_n(int argc, char *argv[], int *idx)
{
	int	i;
	int	option_n;

	i = 1;
	option_n = 0;
	if (argc == 1)
		return (0);
	option_n = is_have_n(argv[i]);
	while (i < argc && is_have_n(argv[i]))
		++i;
	*idx = i;
	return (option_n);
}

int	ft_echo(int argc, char *argv[])
{
	int	idx;
	int	option_n;

	idx = 1;
	option_n = check_option_n(argc, argv, &idx);
	while (idx < argc && argv[idx])
	{
		ft_write(STDOUT_FILENO, argv[idx], ft_strlen(argv[idx]));
		if (idx + 1 != argc)
			ft_write(STDOUT_FILENO, " ", 1);
		++idx;
	}
	if (option_n == 0)
		ft_write(STDOUT_FILENO, "\n", 1);
	return (0);
}
