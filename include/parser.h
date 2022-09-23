/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:43:38 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/17 14:43:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include "struct.h"

typedef struct s_cmd
{
	char			**argv;
	int				argc;
	bool			is_pipe;
	bool			is_dollar;
	int				fd[2];
	int				infile;
	int				outfile;
	char			*cmd_path;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}				t_cmd;

/* replace.c */
void	replace(t_cmd *cmd, t_env *head);

/* replace_utils.c*/
char	*ft_strjoin_free(char *s1, char *s2);
void	delete_argv(t_cmd *cmd, int *i);
void	argv_change(t_cmd *cmd, char *new, int i);

/* parse.c */
void	parse(char *line, t_cmd *cmd);

/* parse_quotes.c */
int		parse_quotes(char c, int quotes, t_cmd *cmd);

/* ft_split_argc.c */
char	**ft_split_argc(char const *s, char c, int *argc);

/* ft_strjoin_char.c */
char	*ft_strjoin_char(char *s, char c);

#endif