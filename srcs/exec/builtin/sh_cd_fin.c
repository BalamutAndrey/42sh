/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd_fin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:38:38 by geliz             #+#    #+#             */
/*   Updated: 2020/11/08 14:48:07 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_chdir_and_env(t_main *main, t_exec *exec, bool param, int8_t p)
{
	char	*temp1;
	char	*temp2;

	temp1 = sh_strdup("OLDPWD", main);
	temp2 = sh_strdup(main->dir, main);
	sh_env_replace(main, temp1, temp2);
	ft_strdel(&main->dir);
	main->dir = sh_strnew(MAX_DIR_LEN, main);
	getcwd(main->dir, MAX_DIR_LEN);
	temp1 = sh_strdup("PWD", main);
	if (param == true)
	{
		temp2 = sh_strdup(exec->argv[p], main);
	}
	else
	{
		temp2 = sh_strdup(main->dir, main);
	}
	sh_env_replace(main, temp1, temp2);
}

char	*sh_chdir_finish(t_exec *exec, t_main *main, bool param, int8_t p)
{
	int		fin;
	char	*finish;

	finish = NULL;
	if ((access(exec->argv[p], 0) == 0) && (access(exec->argv[p], 1) == -1))
	{
		finish = sh_strjoin_arg(main,
			"%s %s %s", "21sh: cd: permission denied: ", exec->argv[p], "\n");
	}
	else
	{
		fin = chdir(exec->argv[p]);
		if (fin != 0)
			finish = sh_strjoin_arg(main, "%s %s %s",
				"21sh: cd: no such file or directory: ", exec->argv[p], "\n");
		else
		{
			sh_chdir_and_env(main, exec, param, p);
		}
	}
	return (finish);
}
