/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:10:08 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 14:38:51 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_cd_no_args(t_exec *exec, t_main *main)
{
	char	*tmp;

	tmp = sh_strdup(exec->argv[0], main);
	sh_remove_argv(exec->argv);
	exec->argv = sh_memalloc(sizeof(char*) * 3, main);
	exec->argv[0] = tmp;
	exec->argv[1] = sh_strdup("~", main);
	exec->argv[2] = NULL;
}

char	*sh_cd(t_exec *exec, t_main *main)
{
	int		i;
	int		n;
	char	*fin;

	i = 0;
	n = 1;
	fin = NULL;
	if (!exec->argv[1])
		sh_cd_no_args(exec, main);
	while (exec->argv[n] != NULL)
	{
		i++;
		n++;
	}
	if (i > 2)
		fin = sh_strdup(
		"21sh: cd: too many arguments\nUsage: cd [-L | -P] directory\n", main);
	else if (i == 2)
		fin = sh_cd_check_param(exec, main);
	else
		fin = sh_cd_change_dir(exec, main, false);
	return (fin);
}

char	*sh_cd_check_param(t_exec *exec, t_main *main)
{
	char	*fin;

	fin = NULL;
	if ((ft_strncmp(exec->argv[1], "-L", 3) == 0) ||
		(ft_strncmp(exec->argv[1], "--logical", 9) == 0))
	{
		sh_cd_change_dir(exec, main, false);
	}
	else if ((ft_strncmp(exec->argv[1], "-P", 3) == 0) ||
			(ft_strncmp(exec->argv[1], "--physical", 10) == 0))
	{
		fin = sh_cd_change_dir(exec, main, true);
	}
	else
	{
		fin = sh_strjoin_arg(main, "%s %s %s", "21sh: cd: string not in pwd: ",
			exec->argv[1], "\nUsage: cd [-L | -P] directory\n");
	}
	return (fin);
}

char	*sh_cd_change_dir(t_exec *exec, t_main *main, bool param)
{
	int8_t	p;
	char	*fin;

	fin = NULL;
	if (param == true)
		p = 2;
	else
		p = 1;
	if (exec->argv[p] != NULL && exec->argv[p][0] != '\0')
	{
		if (exec->argv[p][0] == '~')
			sh_home_dir(exec, main, p);
		else if ((exec->argv[p][0] == '-') && (exec->argv[p][1] == '\0'))
			sh_prev_dir(exec, main, p);
		else if (exec->argv[p][0] != '/')
			sh_no_root_dir(exec, main, p);
	}
	else
		sh_chdir_save_argv(exec, main, p);
	fin = sh_chdir_finish(exec, main, param, p);
	return (fin);
}

void	sh_chdir_save_argv(t_exec *exec, t_main *main, int8_t p)
{
	int16_t	i;

	i = 0;
	while (exec->argv[i])
	{
		ft_strdel(&exec->argv[i]);
		i++;
	}
	free(exec->argv);
	exec->argv = malloc(sizeof(char **) * p + 1);
	exec->argv[0] = sh_strdup("cd", main);
	exec->argv[p] = sh_strdup(main->home, main);
}
