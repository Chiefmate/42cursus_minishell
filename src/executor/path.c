/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:30:44 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/21 17:30:44 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executor.h"

static void	free_path(char **path)
{
	size_t	i;

	i = 0;
	while(path[i])
		free(path[i++]);
	free(path);
	return ;
}

/* external func
 * path.c (Self)
 * 		free_path()
 * is_exist_file()
 */
static char	*get_absolute_path(t_cmd *cmd, char *env_path)
{
	char	*ret;
	char	*slash;
	char	**path;
	int		i;

	i = 0;
	path = ft_split(env_path, ':');
	slash = ft_strjoin("/", cmd->argv[0]);
	while (path[i])
	{
		ret = ft_strjoin(path[i], slash);
		if (is_exist_file(ret))
			break ;
		free(ret);
		i++;
	}
	free(slash);
	if (!path[i])
		ret = NULL;
	free_path(path);
	return (ret);
}

static int	check_relative(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (!ft_alnum(str[i]))
	{
		if (str[i] == '.' || str[i] =='/')
			ret = 1;
		i++;
	}
	return (ret);
}

/* io_file_open.c/io_file_open()에서 호출되어 cmd의 path를 반환
 * external functions
 * path.c (Self)
 * 		check_relative()
 * 		get_absolute_path()
 * ft_getenv()
 * is_exist_file()
 */
char	*get_cmd_path(t_cmd *cmd, t_env *env_head)
{
	char	*ret;
	char	*env_path;

	ret = NULL;
	env_path = ft_getenv(env_head, "PATH");
	if (check_relative(cmd->argv[0]) && is_exist_file(cmd->argv[0]))
		return (ft_strdup(cmd->argv[0]));
	else if (env_path != NULL)
		ret = get_absolute_path(cmd, env_path);
	if (!ret && is_exist_file(cmd->argv[0]))
		return (ft_strdup(cmd->argv[0]));
	return (ret);
}