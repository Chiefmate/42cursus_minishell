/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:36:43 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/28 15:40:06 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_exist_file(char *tmp_file_name)
{
	int fd;

	fd = open(tmp_file_name, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	else
		return (1);
}
