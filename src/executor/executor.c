/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:10:58 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/26 20:44:54 by hyunhole         ###   ########.fr       */
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

/* execute_cmd()의 내부 함수
 * builtin이 아닌 커맨드를 실행시킴
 */
static int	os_builtins(t_cmd *cmd, t_env *env_head)
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

/* do_fork_cmd()와 do_cmd()의 내부 함수
 * builtin을 수행함
 * builtin이 아닌 경우 os_builtins() 호출
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
	return (os_builtins(cmd, env_head));
}

/* executor()의 내부 함수 
 * fork를 수행한 후 execute_cmd를 호출함
 *
 * set_signal()
 * ft_fork()
 * 
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
	/* 자식 프로세스 */
	if (!pid)
	{
		redirect(cmd);
		close_unused_fd(cmd, pid);
		exit_code = execute_cmd(cmd, env_head);
		exit (exit_code);
	}
	/* 부모 프로세스 */
	else
	{
		close_unused_fd(cmd, pid);
		set_signal(IGN, IGN);
	}
	return ;
}

/* executor()의 내부 함수 
 * 바로 execute_cmd를 호출함
*/
static void	do_cmd(t_cmd *cmd, t_env *env_head)
{
	printf("no fork\n");
	g_exit_code = execute_cmd(cmd, env_head);
	close_unused_fd(cmd, 1);
}

/*
 * 외부함수
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
 * 
 * set_signal()
 */
void	executor(t_cmd *cmd_head, t_env *env_head)
{
	t_cmd *cmd_cur;

	char	dbg_buf[50] = {0, };

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
		
		//dbg
		getcwd(dbg_buf, 49);
		printf("exec curr dir is %s\n", dbg_buf);

		/* 파이프있는 경우는 fork, builtin은 fork X 
		 * env도 반드시 전달해야 함
		*/
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