/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:32:30 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 17:45:47 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <signal.h>
// #include <sys/errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
// # include <readline/readline.h>

/* DFL(Default signal handler) IGN (Ignore) */
# define SHE 0
# define DFL 1
# define IGN 2

/* ft_system_call.c */
int		ft_open(char *fname, int oflag, int mode);
int		ft_close(int fd);
void	ft_pipe(int *fds);
void	ft_dup2(int fd1, int fd2);
pid_t	ft_fork(void);

/* exit_with_error.c */
void	exit_with_err(char *s1, char *s2, int exit_code);
void	print_err(char *s);
void	print_err2(char *s1, char *s2);
void	print_err3(char *cmd, char *s1, char *s2);
void	print_quote_err3(char *cmd, char *s1, char *s2);

/* signal.c */
void	signal_handler(int signo);
void	set_signal(int sig_int, int sig_quit);

#endif