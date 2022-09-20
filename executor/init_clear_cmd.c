/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:11:03 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 00:11:03 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executor.h"

int init_heredoc(t_cmd *cmd)
{
  t_cmd *cur;

  cur = cmd;
  while (cur)
  {
    if (heredoc(cur) == -1)
      return (-1);
    cur = cur->next;
  }
  return (0);
}