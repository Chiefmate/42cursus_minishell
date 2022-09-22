/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:11:28 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 18:52:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

<<<<<<< HEAD
# include "./struct.h"
# include "./utils.h"
=======
# define READ 0
# define WRITE 1

>>>>>>> c8111469d2adf0c24b99c39a7123ef8e27180cc6
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
// # include <readline/readline.h>

# include "./struct.h"
# include "./utiles.h"

/* executor.c */
void	executor(t_cmd *cmd_head, t_env *env_head);

/* redirection.c */
void	redirect(t_cmd *cmd);

/* init_clear_cmd.c */
int		init_heredoc(t_cmd *cmd);
void	clear_cmd(t_cmd *cmd_head);

/* heredoc.c */
int		heredoc(t_cmd *cmd_head);

/* check_valid_syntax.c */
int		check_valid_syntax(t_cmd *cmd_head);

/* wait_child.c */
void	wait_child(void);

/* executor_utils.c */
int		is_need_fork(t_cmd *cmd);
void	restore_redirection_char(t_cmd *cmd);

/* path.c */
char	*get_cmd_path(t_cmd *cmd, t_env *env_head);

/* close_unused_fd.c */
void	close_unused_fd(t_cmd *cmd, pid_t pid);

/* io_file_open.c */
int		io_file_open(t_cmd *cmd, t_env *env_head);
void	trim_cmd_argv(t_cmd *cmd, const char *set, int size);

/* tmp_file.c */
char	*get_tmp_file_name(void);
void	delete_tmp_file(void);

#endif