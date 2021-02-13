/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:38:51 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:43:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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

void	sh_exec_standart_fork_parrent(t_main *main, pid_t cpid, t_exec *exec)
{
	main->cpid = cpid;
	if (main->bg == true)
		sh_exec_job(main, exec);
	else
		sh_exec_pid_wait(main, exec);
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
			sh_exec_standart_fork_parrent(main, cpid, exec);
			ft_strdel(&err_built);
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
