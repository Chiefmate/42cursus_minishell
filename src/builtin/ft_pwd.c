/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:58:47 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 20:58:51 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	ft_write(STDOUT_FILENO, pwd, ft_strlen(pwd));
	ft_write(STDOUT_FILENO, "\n", 1);
	free(pwd);
	return (EXIT_SUCCESS);
}