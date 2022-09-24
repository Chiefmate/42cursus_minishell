/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:01:46 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 17:01:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DONE

#include "executor.h"

static void	redirect_pipe_in(t_cmd *cmd)
{
	if (cmd->prev == false)
		return ;
	return (ft_dup2(cmd->prev->fd[READ], STDIN_FILENO));
}

static void	redirect_pipe_out(t_cmd *cmd)
{
	if (cmd->is_pipe == false)
		return ;
	return (ft_dup2(cmd->fd[WRITE], STDOUT_FILENO));
}

static void	redirect_infile(t_cmd *cmd)
{
	if (cmd->infile < 0)
		return ;
	return (ft_dup2(cmd->infile, STDIN_FILENO));
}

static void	redirect_outfile(t_cmd *cmd)
{
	if (cmd->prev == false)
		return ;
	return (ft_dup2(cmd->outfile, STDOUT_FILENO));
}

/* executor.c/do_fork_cmd()에서 호출됨
 * 외부 함수 모두 redirection.c 안에서 static 함수로 구현
 */
void	redirect(t_cmd *cmd)
{
	redirect_pipe_in(cmd);
	redirect_pipe_out(cmd);
	redirect_infile(cmd);
	redirect_outfile(cmd);
	return ;
}