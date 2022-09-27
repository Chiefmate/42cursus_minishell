/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:10:55 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/27 21:15:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* when take a sole pipe with the command "$ |"
 * and enter the command "$?" to check the exit code, 
 * bash says "bash: 258: command not found"
 */ 
static int check_pipe_syntax(t_cmd *cmd)
{
	if (cmd->is_pipe && cmd->argc == 0)
	{
		print_err("syntax error near unexpected token `|'");
		g_exit_code = 258;
		return (-1);
	}
	return (0);
}

/* print_err()
 */
static int check_redirection_file(t_cmd *cmd, int i, int ret)
{
	const char oc[2] = {-76, '\0'};
	const char oa[3] = {-76, -76, '\0'};
	const char ic[2] = {-74, '\0'};
	const char ia[3] = {-74, -76, '\0'};

	if (cmd->argc == 0)
		return (0);
	while (i < cmd->argc)
	{
		if (!ft_strcmp(cmd->argv[i], oc) || !ft_strcmp(cmd->argv[i], oa))
			if (cmd->argv[i + 1] == NULL || ft_strlen(cmd->argv[i + 1]) == 0)
				ret = -1;
		if (!ft_strcmp(cmd->argv[i], ic) || !ft_strcmp(cmd->argv[i], ia))
			if (cmd->argv[i + 1] == NULL || ft_strlen(cmd->argv[i + 1]) == 0)
				ret = -1;
		if (ret == -1)
		{
			print_err("syntax error near unexpected token `newline'");
			g_exit_code = 258;
			return (-1);
		}
		i++;
	}
	return (0);
}

/* try bash with cmd "$$?"
 * and cmd "$?"
 * then you get 127: command not found
 */
static int is_cmd_not_found(t_cmd *cmd)
{
	if (cmd->is_dollar == false && cmd->argc == 1 && 
		!ft_strcmp(cmd->argv[0], ""))
	{
		print_err2("", "command not found");
		g_exit_code = 127;
		return (1);
	}
	return (0);
}

/* called by executor()
 * check if the cmd has valid syntax or not
 * return
 *		0	if valid
 *		-1	otherwise
 * every external functions are static functions in check_valid_syntax.c
 */
int check_valid_syntax(t_cmd *cmd_head)
{
	t_cmd *cur;

	cur = cmd_head;
	if (cur->argc == 0)
		return (-1);
	if (check_pipe_syntax(cmd_head) == -1)
		return (-1);
	while (cur)
	{
		if (is_cmd_not_found(cur) == 1)
			return (-1);
		else if (check_redirection_file(cur, 0, 0) == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}