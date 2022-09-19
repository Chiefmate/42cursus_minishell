/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:17:56 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/16 14:17:56 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*add_redirect_space(char *str, char *line, char c)
{
	if (c == '>')
	{
		line--;
		if (!(*line == '>' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -76);
		line++;
		if (!(*line == '>' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
	}
	else if (c == '<')
	{
		line--;
		if (!(*line == '<' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, -74);
		line++;
		if (!(*line == '<' || *line == ' '))
			str = ft_strjoin_char(str, ' ');
	}
}

static char	*parse_in_pipe(char *str, int *pipe, t_cmd **cmd, t_cmd *next)
{
	if (*pipe == 1)
		exit_with_err("argv error", "||", 1);
	(*cmd)->is_pipe = ture;
	(*cmd)->argv = ft_split_argc(str, ' ', &((*cmd)->argc));
	next = ft_list_init();
	(*cmd)->next = next;
	next->prev = (*cmd);
	(*cmd) = next;
	str = ft_free(str);
	*pipe = 1;
	return (str);
}

static char	*parse_out_pipe()
{
	if ((*line == ';' || *line == '\\') && quotes == 0)
		exit_with_err("symbol error", line, 1);
	else if (quotes != 0 && *line == ' ')
		str = ft_strjoin_char(str, -32);
	else if (quotes == 0 && ft_isspace(*line))
		str = ft_strjoin_char(str, ' ');
	else if ((*line == '>' || *line == '<') && quotes == 0)
		str = add_redirect_space(str, line, *line);
	else
	{
		str = ft_strjoin_char(str, line[0]);
		*pipe = 0;
	}
	return (str);
}

void	parse(char *line, t_cmd *cmd)
{
	t_cmd	*next;
	char	*str;
	int		quotes;
	int		pipe;

	str = NULL;
	next = NULL;
	quotes = 0;
	pipe = 0;
	while (*line)
	{
		quotes = parse_set_quotes(*line, quotes, cmd);
		if (*line == '|' && quotes == 0)
			str = parse_in_pipe(str, &pipe, &cmd, next);
		else
			str = parse_out_pipe(str, line, quotes, &pipe);
		line++;
	}

	if (quotes != 0)
		exit_with_err("quotes error", NULL, 1);
	if (str != NULL)
	{
		cmd->argv = ft_split_argc(str, ' ', &(cmd->argc));
		str = ft_free(str);
	}
}


/* not to submit */
void	test_parse(char *line)
{
	char	*str = NULL;
	int		quotes = 0;
	int		index = 0;
	int		space = 1;
	int		pipe = 0;

	while (*line)
	{
		quotes = parse_set_quotes(*line, quotes); // line 이 \' 혹은 \" 일때 예외 처리를 위해 구분
		
		if (*line == ' ' && space == 0 && quotes == 0)
		{
			printf("[%d] : %s\n", index, str);
			str = ft_free(str);
			space = 1;
			index++;
		}
		else if (*line == '|' && quotes == 0)
		{
			if (space == 0) //공백이 아닐때만 구조체에 넣고 free
			{
				printf("[%d] : %s\n", index, str);
				str = ft_free(str);
			}
			if (pipe == 1) // 기존 값이 파이프일때(파이프가 연속으로 나왔을때) 예외처리
			{
				printf("test exit: ||\n");
				exit(1);
			}
			// 이 자리에 현재 구조체의 is_pipe를 true로 바꾸고 다음 리스트로 넘어가는 동작 넣을 예정
			index = 0;
			space = 1;
			pipe = 1;
		}
		else
		{
			// 해석하지 않는 특수문자 예외처리
			if ((*line == ';' || *line == '\\') && quotes == 0)
			{
				printf("test exit: %c\n", *line);
				exit(1);
			}
			// 연달아서 공백이 나오는 경우 예외처리
			if (!(*line == ' ' && space == 1))
			{
				str = ft_strjoin_char(str, line[0]);
				space = 0;
				pipe = 0;
			}
		}
		line++;
	}
	if (quotes != 0) // 닫히지 않은 따옴표 예외처리
	{
		printf("test exit: quotes error\n");
		exit(1);
	}
	if (str != NULL) // 마지막에 출력하지 않은 문자열이 남은 경우 처리
	{
		printf("[%d] : %s\n", index, str);
		str = ft_free(str);
	}
}