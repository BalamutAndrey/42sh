/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:43:11 by eboris            #+#    #+#             */
/*   Updated: 2021/02/12 15:36:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_check_stout(t_exec *exec)
{
	t_redirect	*tmp;
	char		*ret;

	tmp = exec->redir;
	while (tmp)
	{
		if (tmp->st_out == false)
			exit(1);
		tmp = tmp->next;
	}
	//Нужен ли тут ret?
	(void)ret;
}

char	*sh_exec_other_builtin(t_exec *exec, t_main *main, char *finish)
{
	if (ft_strcmp(exec->argv[0], "unsetenv") == 0)
	{
		finish = sh_builtin_unsetenv(exec, main);
		sh_builtin_unset(exec, main);
	}
	else if (ft_strcmp(exec->argv[0], "set") == 0)
		sh_builtin_set(main);
	else if (ft_strcmp(exec->argv[0], "unset") == 0)
	{
		sh_builtin_unset(exec, main);
		finish = sh_builtin_unsetenv(exec, main);
		ft_strdel(&finish);
	}
	else if (ft_strcmp(exec->argv[0], "export") == 0)
		sh_builtin_export(exec, main);
	else if (ft_strcmp(exec->argv[0], "unalias") == 0)
		finish = sh_builtin_unalias(exec, main);
	else if (ft_strcmp(exec->argv[0], "jobs") == 0)
		sh_builtin_jobs(exec, main);
	else if (ft_strcmp(exec->argv[0], "fg") == 0)
		finish = sh_builtin_fg(exec, main);
	return (finish);
}

char	*sh_exec_builtin(t_exec *exec, t_main *main)
{
	char	*finish;

	finish = NULL;
	if (ft_strcmp(exec->argv[0], "cd") == 0)
		finish = sh_cd(exec, main);
	else if (ft_strcmp(exec->argv[0], "pwd") == 0)
		sh_pwd(exec, main);
	else if (ft_strcmp(exec->argv[0], "echo") == 0)
	{
		sh_exec_check_stout(exec);
		sh_builtin_echo(main, exec);
	}
	else if (ft_strcmp(exec->argv[0], "exit") == 0)
		sh_exit(exec, main);
	else if (ft_strcmp(exec->argv[0], "alias") == 0)
		finish = sh_alias(exec, main);
	else if (ft_strcmp(exec->argv[0], "type") == 0)
		sh_type(exec, main);
	else if (ft_strcmp(exec->argv[0], "setenv") == 0)
		finish = sh_builtin_setenv(exec, main);
	else if (ft_strcmp(exec->argv[0], "env") == 0)
		sh_builtin_env(main);
	else
		finish = sh_exec_other_builtin(exec, main, finish);
	return (finish);
}
