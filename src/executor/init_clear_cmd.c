/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:11:03 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 18:48:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DONE

#include "../include/executor.h"

/* executor()에서 호출되어 heredoc()을 호출함
 * return
 * 		0	if successful
 * 		-1	if error
 * 
 * 사용 함수 (Dependencies)
 * heredoc.c
 * 		heredoc()
 * tmp_file.c
 * 		delete_tmp_file()
 * 
 * ft_close()
 * ft_free()
 */
int	init_heredoc(t_cmd *cmd)
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

/* t_cmd 연결리스트의 모든 커맨드 삭제
 * 
 * 사용 함수 (Dependencies)
 * ft_close()
 * ft_free()
 * 
 * tmp_file.c
 * 		delete_tmp_file()
 */
void	clear_cmd(t_cmd *cmd_head)
{
	t_cmd	*cur;

	cur = cmd_head;
	while (cur)
	{
		if (cur->fd[READ] > 0)
			ft_close(cur->fd[READ]);
		if (cur->infile > 0)
			ft_close(cur->infile);
		if (cur->outfile > 0)
			ft_close(cur->outfile);
		if (cur->cmd_path != NULL)
			cur->cmd_path = ft_free(cur->cmd_path);
		cur = cur->next;
	}
	delete_tmp_file();
	return ;
}