/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:10:58 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/26 20:55:04 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	**get_env_arr(t_env *head)
{
	int		i;
	int		size;
	char	*key;
	t_env	*tmp;
	char	**ret;

	i = 0;
	size = 0;
	tmp = head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	ret = malloc(sizeof(char *) * size);
	tmp = head;
	while (i < size - 1)
	{
		key = ft_strjoin(tmp->key, "=");
		ret[i] = ft_strjoin(key, tmp->value);
		i++;
		tmp = tmp->next;
		free(key);
	}
	ret[i] = NULL;
	return (ret);
}

/* called by execute_cmd()
 * executes external functions, which are not builtin
 */
static int	execute_external(t_cmd *cmd, t_env *env_head)
{
	char	*env_path;
	char	**env_arr;

	env_path = ft_getenv(env_head, "PATH");
	if (env_path == NULL && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (env_path != NULL && ft_strlen(env_path) == 0 && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "command not found");
		return (127);
	}
	env_arr = get_env_arr(env_head);
	ft_execve(cmd->cmd_path, cmd->argv, env_arr);
	return (EXIT_FAILURE);
}

/* called by do_fork_cmd() and do_cmd()
 * executes builtin
 * if not builtin func, executes execute_external()
 * 
 * executor_utils.c
 * 		restore_redirection_char()
 */
static int	execute_cmd(t_cmd *cmd, t_env *env_head)
{
	restore_redirection_char(cmd);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd->argc, cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(cmd->argv[1], env_head));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(env_head));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(cmd));
	return (execute_external(cmd, env_head));
}

/* called by executor()
 * fork a process and calls execute_cmd()
 *
 * utils/signal.c
 * 		set_signal()
 * utils/ft_system_call.c
 * 		ft_fork()
 * redirection.c
 * 		redirect()
 * close_unused_fd.c
 * 		close_unused_fd()
 */
static void	do_fork_cmd(t_cmd *cmd, t_env *env_head)
{
	pid_t	pid;
	int		exit_code;

	printf("entered fork\n");
	set_signal(DFL, DFL);
	pid = ft_fork();
	if (!pid)
	{
		redirect(cmd);
		close_unused_fd(cmd, pid);
		exit_code = execute_cmd(cmd, env_head);
		exit (exit_code);
	}
	else
	{
		close_unused_fd(cmd, pid);
		set_signal(IGN, IGN);
	}
	return ;
}

/* called by executor()
 * calls execute_cmd
*/
static void	do_cmd(t_cmd *cmd, t_env *env_head)
{
	printf("no fork\n");
	g_exit_code = execute_cmd(cmd, env_head);
	close_unused_fd(cmd, 1);
}

/*
 * External Functions
 * executor.c (self)
 * 		do_fork_cmd()
 * 		do_cmd()
 * check_valid_syntax.c
 * 		check_valid_syntax()
 * init_clear_cmd.c
 * 		init_heredoc()
 * 		clear_cmd()
 * io_file_open.c
 * 		io_file_open()
 * executor_utils.c
 * 		is_need_fork()
 * wait_child.c
 * 		wait_child()
 * utils/signal.c
 * 		set_signal()
 */
void	executor(t_cmd *cmd_head, t_env *env_head)
{
	t_cmd *cmd_cur;

	cmd_cur = cmd_head;
	if (check_valid_syntax(cmd_head) == -1)
		return (clear_cmd(cmd_head));
	if (init_heredoc(cmd_cur) == -1)
		return (clear_cmd(cmd_head));
	while (cmd_cur)
	{
		if (io_file_open(cmd_cur, env_head) == -1)
		{
			cmd_cur = cmd_cur->next;
			continue ;
		}
		if (is_need_fork(cmd_cur))
			do_fork_cmd(cmd_cur, env_head);
		else
			do_cmd(cmd_cur, env_head);
		cmd_cur = cmd_cur->next;
	}
	wait_child();
	set_signal(SHE, SHE);
	return (clear_cmd(cmd_head));
}