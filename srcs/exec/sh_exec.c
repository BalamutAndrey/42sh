/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:46:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_print_error(int16_t error, t_main *main)
{
	if (main->alias_cont)
	{
		ft_fprintf(STDOUT_FILENO, "%s", main->alias_cont);
		if (error == 0)
			exit(0);
	}
	if (error <= 0)
		exit(0);
	if (error == 1)
		ft_fprintf(STDERR_FILENO, "21sh: Access 0 error. Command not found.\n");
	else if (error == 2)
		ft_fprintf(STDERR_FILENO, "21sh: Access 1 error.\n");
	else if (error == 3)
		ft_fprintf(STDERR_FILENO, "21sh: Not a file of link.\n");
	else if (error == 4)
		ft_fprintf(STDERR_FILENO, "21sh: Unknown error.\n");
	exit(2);
}

t_exec	*sh_exec_pipes_hub(t_exec *exec, t_main *main)
{
	sh_exec_piped_commands(exec, main);
	sh_exec_set_pipes_exit_s(exec, main);
	exec = exec->next;
	while (exec && exec->pipe == true)
		exec = exec->next;
	setpgid(0, 0);
	tcsetpgrp(STDOUT_FILENO, main->pid);
	return (exec);
}

void	sh_exec(t_main *main, t_exec *exec)
{
	while (exec)
	{
		main->exec_curr = exec;
		if (!main->vars)
			sh_get_vars_from_env(main);
		tcsetattr(main->fd, TCSANOW, &main->t_start);
		sh_signal_parrent(main);
		if (exec->next && exec->next->pipe == true)
		{
			exec = sh_exec_pipes_hub(exec, main);
		}
		else
		{
			if (!exec->argv)
				sh_check_variables(exec, main);
			sh_change_envvars_in_exec(main, exec);
			sh_standart_exec(exec, main);
			main->ex_code = exec->exit_s;
			exec = sh_or_if_and_if_check(exec);
		}
		tcsetattr(main->fd, TCSANOW, &main->t_curr);
	}
	sh_exec_jobs_fin(main);
}
