/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:39:24 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 18:39:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* Called by execute.c/do_fork_cmd()
 */
void	close_unused_fd(t_cmd *cmd, pid_t pid)
{
	if (!pid)
	{
		if (cmd->fd[READ] != -2)
			cmd->fd[READ] = ft_close(cmd->fd[READ]);
	}
	else
	{
		if (cmd->fd[WRITE] != -2)
			cmd->fd[WRITE] = ft_close(cmd->fd[WRITE]);
	}
	return ;
}
