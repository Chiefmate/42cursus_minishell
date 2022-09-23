/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:57:40 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/23 20:22:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*get_pwd_key_value(const char *key)
{
	char *tmp;
	char *pwd_key_value;

	tmp = ft_getcwd(NULL, 0);
	pwd_key_value = ft_strjoin(key, tmp);
	free(tmp);
	return (pwd_key_value);
}

void	export_pwd(const char *pwd, t_env *env_head)
{
	char *tmp_pwd;

	tmp_pwd = get_pwd_key_value(pwd);
	export_key_value(env_head, tmp_pwd);
	free(tmp_pwd);
}