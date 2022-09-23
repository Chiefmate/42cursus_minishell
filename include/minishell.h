/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:35:02 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 00:35:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./struct.h"
# include "./utils.h"
# include "./executor.h"
# include "./builtin.h"
# include "../libft/libft.h"

int		is_white_space(char *line);
void	main_init(int argc, char *argv[]);

#endif