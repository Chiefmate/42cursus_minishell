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

#endif