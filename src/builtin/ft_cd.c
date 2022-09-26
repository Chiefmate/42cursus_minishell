/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:57:43 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/26 20:37:57 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	cd_tilde(t_env *env_head)
{
	int exit_code;
	char *home;
	char *tmp_pwd;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", home, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_tilde_path(char *path, t_env *env_head)
{
	int exit_code;
	char *home;
	char *tmp_pwd;
	char *home_path;

	exit_code = EXIT_FAILURE;
	home = getenv("HOME");
	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		home_path = ft_strjoin(home, path + 1);
		exit_code = chdir(home_path);
		if (exit_code == -1)
			print_err3("cd", home_path, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(home_path);
		free(tmp_pwd);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_home(char *path, t_env *env_head)
{
	int		exit_code;
	char	*home;
	char	*tmp_pwd;

	char	dbg_buf[50] = {0, };

	exit_code = EXIT_FAILURE;
	home = ft_getenv(env_head, "HOME");
	
	//dbg
	printf("home is %s\n", home);
	getcwd(dbg_buf, 49);
	printf("curr dir is %s\n", dbg_buf);

	if (home == NULL)
		print_err2("cd", "home not set");
	else
	{
		tmp_pwd = get_pwd_key_value("OLDPWD=");
		exit_code = chdir(home);
		if (exit_code == -1)
			print_err3("cd", path, strerror(errno));
		else
			export_key_value(env_head, tmp_pwd);
		free(tmp_pwd);

		// dbg
		getcwd(dbg_buf, 49);
		printf("changed dir is %s\n", dbg_buf);
		printf("exit_code is %d\n", exit_code);
	}
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

static int	cd_path(char *path, t_env *env_head)
{
	int exit_code;
	char *tmp_pwd;

	exit_code = EXIT_FAILURE;
	tmp_pwd = get_pwd_key_value("OLDPWD=");
	exit_code = chdir(path);
	if (exit_code == -1)
		print_err3("cd", path, strerror(errno));
	else
		export_key_value(env_head, tmp_pwd);
	free(tmp_pwd);
	if (exit_code != -1)
		export_pwd("PWD=", env_head);
	return (exit_code);
}

int	ft_cd(char *path, t_env *env_head)
{
	//debug
	printf("entered cd with path: %s\n", path);

	if (path == NULL)
		return (cd_home(path, env_head));
	else if (!ft_strcmp("~", path))
		return (cd_tilde(env_head));
	else if (!ft_strncmp("~/", path, 2))
		return (cd_tilde_path(path, env_head));
	else
		return (cd_path(path, env_head));
}