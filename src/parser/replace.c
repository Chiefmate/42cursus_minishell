/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:51:45 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/17 14:51:45 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* concatenates letters, numbers, and '_'
 * deals with $?
 */
static char	*replace_loop_dollar(char c, char *new, t_env *head, int quotes)
{
	static char	*env = NULL;

	if (ft_isalnum(c) || c == '_')
		env = ft_strjoin_char(env, c);
	else if (c == '?' && env == NULL)
	{
		env = ft_itoa(g_exit_code);
		new = ft_strjoin_free(new, env);
		env = ft_free(env);
	}
	else
	{
		if (env != NULL)
		{
			new = ft_strjoin_free(new, ft_getenv(head, env));
			if (!(c == '\"' && quotes != 1) && !(c == '\'' && quotes != 2))
				new = ft_strjoin_char(new, c);
			env = ft_free(env);
			g_exit_code = 0;
		}
		else
			new = ft_strjoin_char(new, '$');
	}
	return (new);
}

static int	dollar_check(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '$')
		return (1);
	else
		return (0);
}

static char	*replace_loop_else(char c, char *new, int quotes)
{
	char	*ret;

	ret = NULL;
	if (c == -32)
		ret = ft_strjoin_char(new, ' ');
	else if (!(c == '\"' && quotes != 1) && !(c == '\'' && quotes != 2))
		ret = ft_strjoin_char(new, c);
	else
		return (new);
	return (ret);
}

static char	*replace_loop(t_cmd *cmd, t_env *head, int arg_cnt)
{
	int		i;
	char	*ret;
	int		dollar;
	int		quotes;

	i = 0;
	dollar = 0;
	quotes = 0;
	ret = NULL;
	while (i <= (int)ft_strlen(cmd->argv[arg_cnt]))
	{
		quotes = parse_quotes(cmd->argv[arg_cnt][i], quotes, cmd);
		if (cmd->argv[arg_cnt][i] == '$' && quotes != 1 && dollar == 0)
			dollar = 1;
		else if (dollar == 1)
		{
			ret = replace_loop_dollar(cmd->argv[arg_cnt][i], ret, head, quotes);
			dollar = dollar_check(cmd->argv[arg_cnt][i]);
		}
		else
			ret = replace_loop_else(cmd->argv[arg_cnt][i], ret, quotes);
		i++;
	}
	return (ret);
}

/* replace function
 * used functions: replace_while,delete_argv, argv_change, ft_strdup
 * replace 
 */

void	replace(t_cmd *cmd, t_env *head)
{
	int		i;
	char	*new;

	while (cmd)
	{
		i = 0;
		while (i < cmd->argc)
		{
			new = replace_loop(cmd, head, i);
			if (new == NULL && cmd->is_dollar)
				delete_argv(cmd, &i);
			else if (new == NULL)
			{
				new = ft_strdup("");
				argv_change(cmd, new, i);
			}
			else
				argv_change(cmd, new, i);
			i++;
		}
		cmd = cmd->next;
	}
	return ;
}
