/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2021/02/10 01:25:27 by geliz            ###   ########.fr       */
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

int16_t	sh_exec_prog(t_exec *exec, t_main *main, char *err_built)
{
	int16_t	error;

	error = -1;
	sh_path_add(main, exec);
	if (!exec->argv)
		return (-1);
	else if (sh_run_access(exec->argv) == 6)
		sh_exec_builtin(exec, main);
	else if (err_built != NULL)
	{
		ft_fprintf(STDERR_FILENO, "%s", err_built);
		ft_strdel(&err_built);
	}
	else if ((error = sh_run_access(exec->argv)) == 0)
	{
		sh_exec_setpgid(exec->bg, main);
		sh_signal_child();
		execve(exec->argv[0], exec->argv, main->envp_curr);
	}
	return (error);
}

void	sh_exec_standart_fork(t_exec *exec, t_main *main, char *err_built)
{
	pid_t	cpid;
	int16_t	err;
	int		r_err;
	int		status;

	r_err = 0;
	if (err_built || (sh_run_access(exec->argv) != 5) || main->alias_cont)
	{
		cpid = fork();
		if (cpid == 0)
		{
			if (exec->redir)
				r_err = sh_redirects_hub(exec, main);
			if (r_err >= 0 && (((err = sh_exec_prog(exec, main,
					err_built)) != 0) || main->alias_cont))
				sh_exec_print_error(err, main);
		}
		else
		{
			main->cpid = cpid;
			status = sh_exec_job(main, exec);
			ft_strdel(&err_built);
//			sh_signal_status(status, cpid);
		}
	}
}

void	sh_standart_exec(t_exec *exec, t_main *main)
{
	int16_t	error;
	char	*err_built;
	int		redir_err;

	err_built = NULL;
	redir_err = 0;
	if (exec->pipe == true || (exec->next && exec->next->pipe == true))
	{
		if (exec->redir)
			redir_err = sh_redirects_hub(exec, main);
		if (sh_run_access(exec->argv) == 5)
			err_built = sh_exec_builtin(exec, main);
		if (redir_err >= 0 &&
			(error = sh_exec_prog(exec, main, err_built)) != 0)
			sh_exec_print_error(error, main);
	}
	else
	{
		if (sh_run_access(exec->argv) == 5)
			err_built = sh_exec_builtin(exec, main);
		sh_exec_standart_fork(exec, main, err_built);
	}
}

void	sh_exec(t_main *main, t_exec *exec)
{
	while (exec)
	{
		if (!main->vars)
			sh_get_vars_from_env(main);
		sh_signal_parrent(main);
		if (exec->next && exec->next->pipe == true)
		{
			sh_exec_piped_commands(exec, main);
			sh_exec_set_pipes_exit_s(exec, main);
			exec = exec->next;
			while (exec && exec->pipe == true)
				exec = exec->next;
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
		tcsetpgrp(STDOUT_FILENO, main->pid);
		tcsetattr(STDOUT_FILENO, TCSANOW, &main->t_curr);
	}
	sh_exec_jobs_fin(main);
}
