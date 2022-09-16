/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:33:39 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/07 16:33:39 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

int is_white_space(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 9 && *line <= 13))
		{
			return (0);
		}
		line++;
	}
	return (1);
}

void main_init(int argc, char *argv[])
{
	struct termios term;

	/*/
		if (argc != 1)
			exit_with_err("argument input error", NULL, 126);
	/*/
	tcgetattr(STDIN_FILENO, &term);
	term.c_cflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	set_signal(SHE, SHE);
	g_exit_code = 0;
	(void)argc;
	(void)argv;
}

int main(int argc, char *argv[], char *envp[])
{
	char *line;
	t_cmd *cmd;
	t_env env_head;
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	main_init(argc, argv);
	init_env_list(&env_head, envp);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break;
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			cmd = ft_list_init();
		}
	}

	return (0);
}
