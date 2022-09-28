/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:58:18 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/28 16:41:40 by jham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_starting_with_digit(char *key_value)
{
	if (ft_isdigit(*key_value))
		return (1);
	return (0);
}

int	is_have_space(char *key_value, char set)
{
	while (*key_value && *key_value != set)
	{
		if (ft_isspace(*key_value))
			break ;
		++key_value;
	}
	if (*key_value == set)
		return (0);
	return (1);
}

int	is_have_specific_char(char *key_value, char c)
{
	while (*key_value)
	{
		if (*key_value == c)
			break ;
		++key_value;
	}
	if (*key_value == '\0')
		return (0);
	return (1);
}

int	is_valid_letters(char *key_value)
{
	while (*key_value)
	{
		if (!ft_isalnum(*key_value) && *key_value != '_' && *key_value != '=')
			return (0);
		++key_value;
	}
	return (1);
}

int	check_valid_identifier(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_letters(argv[i]) || !is_have_specific_char(argv[i], '='))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_have_space(argv[i], '='))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		if (is_starting_with_digit(argv[i]))
		{
			print_quote_err3("export", argv[i], "not a valid identifier");
			return (-1);
		}
		i++;
	}
	return (0);
}
