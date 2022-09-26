/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:19:37 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/26 20:55:27 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* 해당 커맨드가 fork한 뒤 실행되어야하는지 판단
 *
 * return	1	fork 해야할 때
 *			0	builtin이라 fork 안할 때
 */
int	is_need_fork(t_cmd *cmd)
{
	/* 앞 뒤로 명령어가 더 있는 경우 fork */
	if (cmd->prev != NULL)
		return (1);
	if (cmd->is_pipe == true)
		return (1);
	if (cmd->infile != -2)
		return (1);
	if (cmd->outfile != -2)
		return (1);
	/* 파이프 만들 필요도 없고, builtin인 경우 fork 안함 */
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (0);
	return (1);
}

/* called by execute_cmd()
 *
 * -74, -76로 바꾸었다가 실행 전 돌리는 이유 확인필요
 */
void	restore_redirection_char(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd->argv[i])
	{
		j = 0;
		while (cmd->argv[i][j])
		{
			if (cmd->argv[i][j] == -74)
				cmd->argv[i][j] = '<';
			else if (cmd->argv[i][j] == -76)
				cmd->argv[i][j] = '>';
			j++;
		}
		i++;
	}
}