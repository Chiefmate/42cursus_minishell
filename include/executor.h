/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:11:28 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 00:11:28 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./struct.h"
# include "./utiles.h"
# include <sys/types.h>
# include <fcntl.h>

void trim_cmd_argv(t_cmd *cmd, const char *set, int size);

#endif