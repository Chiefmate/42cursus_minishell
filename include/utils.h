/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:32:30 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 00:32:30 by hyunhole         ###   ########.fr       */
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

# define SHE 0
# define DFL 1
# define IGN 2

int		ft_close(int fd);
int		ft_open(char *fname, int oflag, int mode);

void	print_err(char *str);

#endif