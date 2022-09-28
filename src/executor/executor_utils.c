/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:19:37 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/28 16:20:29 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* decides whether the cmd needs fork() sys call or not
 *
 * return	1	if fork() needed
 *			0	otherwise
 */
int	is_need_fork(t_cmd *cmd)
{
	if (cmd->prev != NULL)
		return (1);
	if (cmd->is_pipe == true)
		return (1);
	if (cmd->infile != -2)
		return (1);
	if (cmd->outfile != -2)
		return (1);
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
 * restores '<' and '>'
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

char	**get_env_arr(t_env *head)
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
		ret[i++] = ft_strjoin(key, tmp->value);
		tmp = tmp->next;
		free(key);
	}
	ret[i] = NULL;
	return (ret);
}
