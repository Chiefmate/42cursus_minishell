/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:58:02 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/28 11:18:52 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ft_env(t_env *cur)
{
	while (cur->key != 0)
	{
		ft_write(STDOUT_FILENO, cur->key, ft_strlen(cur->key));
		ft_write(STDOUT_FILENO, "=", 1);
		ft_write(STDOUT_FILENO, cur->value, ft_strlen(cur->value));
		ft_write(STDOUT_FILENO, "\n", 1);
		cur = cur->next;
	}
	return (0);
}