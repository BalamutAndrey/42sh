/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:43:11 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:16:13 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
		sh_exit(main, 0);
	else if (ft_strcmp(exec->argv[0], "setenv") == 0)
		finish = sh_builtin_setenv(exec, main);
	else if (ft_strcmp(exec->argv[0], "unsetenv") == 0)
		finish = sh_builtin_unsetenv(exec, main);
	else if (ft_strcmp(exec->argv[0], "env") == 0)
		sh_builtin_env(main);
	return (finish);
}
