/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:43:11 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 18:57:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

// void	sh_alias_cont_print(t_exec *exec, t_main *main)
// {	
// 	pid_t	cpid;
// 	int		r_err;
// 	int		status;

// 	r_err = 0;
// 	cpid = fork();
// 	if (cpid == 0)
// 	{
// 		if (exec->redir)
// 			r_err = sh_redirects_hub(exec, main);
// 		ft_fprintf(STDOUT_FILENO, "%s", main->alias_cont);
// 	}
// 	else
// 	{
// 		main->cpid = cpid;
// 		waitpid(cpid, &status, 0);
// 		main->cpid = -1;
// 		sh_signal_status(status, cpid);
// 	}
// }

char	*sh_exec_builtin(t_exec *exec, t_main *main)
{
	char	*finish;

	finish = NULL;
	if (ft_strcmp(exec->argv[0], "cd") == 0)
		finish = sh_cd(exec, main);
	else if (ft_strcmp(exec->argv[0], "pwd") == 0)
		sh_pwd(exec, main);
	else if (ft_strcmp(exec->argv[0], "echo") == 0)
		sh_builtin_echo(main, exec);
	else if (ft_strcmp(exec->argv[0], "exit") == 0)
		sh_exit(exec, main);
	else if (ft_strcmp(exec->argv[0], "alias") == 0)
	{
		finish = sh_alias(exec, main);
		// if (main->alias_cont)
		// 	sh_alias_cont_print(exec, main);
	}
	else if (ft_strcmp(exec->argv[0], "type") == 0)
		sh_type(exec, main);
	else if (ft_strcmp(exec->argv[0], "setenv") == 0)
		finish = sh_builtin_setenv(exec, main);
	else if (ft_strcmp(exec->argv[0], "unsetenv") == 0)
	{
		finish = sh_builtin_unsetenv(exec, main);
		sh_builtin_unset(exec, main);
	}
	else if (ft_strcmp(exec->argv[0], "env") == 0)
		sh_builtin_env(main);
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
	return (finish);
}
