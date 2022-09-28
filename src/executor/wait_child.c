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
 * waits a child process
 *
 * External Functions
 * wait()
 * 
 * WEXITSTATUS()
 * WIFSIGNALED()
 * WTERMSIG()
 */
void	wait_child(void)
{
	int	wstatus;
	int	signo;
	int	i;

	i = 0;
	while (wait(&wstatus) != -1)
	{
		if (WIFSIGNALED(wstatus))
		{
			signo = WTERMSIG(wstatus);
			if (signo == SIGINT && i++ == 0)
				ft_putstr_fd("^C\n", STDERR_FILENO);
			else if (signo == SIGQUIT && i++ == 0)
				ft_putstr_fd("^\\Quit: 3\n", STDERR_FILENO);
			g_exit_code = 128 + signo;
		}
		else
			g_exit_code = WEXITSTATUS(wstatus);
	}
}
