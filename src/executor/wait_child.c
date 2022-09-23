/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:43:26 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 15:43:26 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* 
 * 이해 필요
 *
 * 외부함수
 * wait()
 * 
 * WIFSIGNALED()
 * WTERMSIG()
 * WEXITSTATUS()
 */
void	wait_child(void)
{
	int	status;
	int	signo;
	int	i;

	i = 0;
	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT && i++ == 0)
				ft_putstr_fd("^C\n", STDERR_FILENO);
			else if (signo == SIGQUIT && i++ == 0)
				ft_putstr_fd("^\\Quit: 3\n", STDERR_FILENO);
			g_exit_code = 128 + signo;
		}
		else
			g_exit_code = WEXITSTATUS(status);
	}
}