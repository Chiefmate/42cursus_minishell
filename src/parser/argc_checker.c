/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:49:40 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/24 17:55:10 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	argc_zero(t_cmd *tmp, t_cmd **ptr, t_cmd **head)
{
	tmp = (*ptr)->next;
	tmp->prev = NULL;
	(*head)->argv = ft_free((*head)->argv);
	*head = ft_free((*head));
	*head = tmp;
	*ptr = tmp;
}

void	argc_checker(t_cmd **cmd)
{
	t_cmd	*ptr;
	t_cmd	*tmp;

	tmp = NULL;
	ptr = *cmd;
	while (ptr)
	{
		if (ptr->prev == NULL && ptr->next == NULL)
			return ;
		if (ptr->argc == 0 && ptr->prev == NULL)
			argc_zero(tmp, &ptr, cmd);
		else if (ptr->argc == 0)
		{
			tmp = ptr->prev;
			tmp->next = ptr->next;
			ptr->argv = ft_free(ptr->argv);
			ptr = ft_free(ptr);
			ptr = tmp->next;
			if (ptr)
				ptr->prev = tmp;
		}
		else
			ptr = ptr->next;
	}
}