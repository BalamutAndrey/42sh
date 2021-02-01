/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2021/02/01 17:10:21 by geliz            ###   ########.fr       */
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
		execve(exec->argv[0], exec->argv, main->envp_curr);
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
			if (r_err >= 0 && (((err = sh_exec_prog(exec, main, err_built)) != 0) ||
				main->alias_cont))
				sh_exec_print_error(err, main);
		}
		else
		{
			main->cpid = cpid;
			waitpid(cpid, &status, 0);
			exec->exit_s = status;
	//		ft_printf("status = %i\n", status);
			main->cpid = -1;
			ft_strdel(&err_built);
			sh_signal_status(status, cpid);
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

t_exec	*sh_or_if_and_if_check(t_exec *exec)
{
	t_exec	*tmp;

	return (exec->next);
	tmp = exec;
	if (!exec->next)
		return (NULL);
	if (exec->andif == false && exec->orif == false)
		return (exec->next);
	if (exec->andif == true)
	{
		if (exec->exit_s == 0)
		{
			return (exec->next);
		}
		else
		{
			while (tmp)
			{
				if ((tmp->next && tmp->next->andif == true) || !tmp->next)
					tmp = tmp->next;
				else if (tmp->next && tmp->next->andif == false && tmp->next->orif == false)
					return (tmp->next);
				else if (tmp->next && tmp->next->orif == true)
					return (tmp->next);
			}
			return (tmp);
		}
	}
	if (exec->orif == true)
	{
		if (exec->exit_s != 0)
			return (exec->next);
		else
		{
			while (tmp)
			{
				if ((tmp->next && tmp->next->orif == true) || !tmp->next)
					tmp = tmp->next;
				else if (tmp->next && tmp->next->andif == false && tmp->next->orif == false)
					return (tmp->next);
				else if (tmp->next->andif == true)
					return (tmp->next);
			}
			return (tmp);
		}
	}
	return (exec->next);
}

void	sh_exec(t_main *main, t_exec *exec)
{
	while (exec)
	{
		if (!main->vars)
			sh_get_vars_from_env(main);
//		sh_check_variables(exec, main);
		tcsetattr(main->fd, TCSANOW, &main->t_start);
		ft_printf("exec->&& = %i exec->|| = %i\n", exec->andif, exec->orif);
		if (exec->next && exec->next->pipe == true)
		{
			sh_exec_piped_commands(exec, main);
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
			exec = sh_or_if_and_if_check(exec);
//			exec = exec->next;
		}
		tcsetattr(main->fd, TCSANOW, &main->t_curr);
	}
}
