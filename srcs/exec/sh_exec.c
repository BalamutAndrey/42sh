/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2021/02/07 19:09:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exit_code_check(t_exec *exec, int status);
/*
NEW FILE 
*/

t_jobs	*sh_exec_new_job(pid_t pid, char *cmd, t_main *main)
{
	t_jobs	*job;
	t_jobs	*tmp;

	job = sh_memalloc(sizeof(t_jobs), main);
	job->next = NULL;
	if (!main->jobs)
		job->num = 1;
	else
	{
		tmp = main->jobs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = job;
		job->num = tmp->num + 1;
	}
	job->pid = pid;
	job->cmd = cmd;
	return (job);
}

char	*sh_exec_job_get_cmd(char **argv, t_main *main)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (argv[i])
	{
		tmp = sh_strjoin_arg(main, "%s %s %s", tmp, " ", argv[i]);
		i++;
	}
	return (tmp);
}

void	sh_exec_jobs_put_signes(t_main *main)
{
	t_jobs	*tmp;

	tmp = main->jobs;
	while (tmp)
	{
		if (!tmp->next)
			tmp->sign = '+';
		else if (!tmp->next->next)
			tmp->sign = '-';
		else
			tmp->sign = ' ';
		tmp = tmp->next;
	}
}

void	sh_exec_add_job(t_main *main, t_jobs *job)
{
	t_jobs	*tmp;

	if (!main->jobs)
		main->jobs = job;
	else
	{
		tmp = main->jobs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = job;
		job->next = NULL;
	}
	sh_exec_jobs_put_signes(main);
}

void	sh_exec_remove_job(t_main *main, t_jobs *job)
{
	t_jobs	*tmp;
	t_jobs	*prev;

	tmp = main->jobs;
	if (ft_memcmp(main->jobs, job, sizeof(t_jobs)) == 0)
	{
		main->jobs = main->jobs->next;
//		sh_delete_job(tmp);
	}
	else
	{
		prev = main->jobs;
		tmp = main->jobs->next;
		while (tmp)
		{
			if (ft_memcmp(tmp, job, sizeof(t_jobs)) == 0)
			{
				prev->next = tmp->next;
				//sh_delete_job(tmp);
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

int		sh_exec_find_job(t_main *main, t_jobs *job)
{
	t_jobs	*tmp;

	tmp = main->jobs;
	while (tmp)
	{
		if (ft_memcmp(main->jobs, job, sizeof(t_jobs)) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		sh_exec_wait(t_jobs *job, t_main *main, t_exec *exec)
{
	int		status;
	int		ret;

	status = 1;
	ret = waitpid(job->pid, &status, WUNTRACED);
	if (WIFSTOPPED(status))
	{
		job->state = STOPPED;
		if (sh_exec_find_job(main, job) == 1)
			sh_exec_add_job(main, job);
		ft_printf("\n[%d]%c %d Stopped    %s\n",
			job->num, job->sign, job->pid, job->cmd);
	}
	else
	{

		
		if (sh_exec_find_job(main, job) == 0)
			sh_exec_remove_job(main, job);
		else
			job = NULL;
			//sh_exec_delete_job(job);
	}
	sh_exit_code_check(exec, status);
//	sh_signal_status(status, main->cpid);
	return (status);
}

int		sh_exec_job(t_main *main, t_exec *exec)
{
	int		status;
	char	*cmd;
	t_jobs	*job;

	cmd = sh_exec_job_get_cmd(exec->argv, main);
	job = sh_exec_new_job(main->cpid, cmd, main);
	setpgid(0, 0);
	status = 0;
	if (exec->bg == 0)
	{
//		waitpid(job->pid, &status, WUNTRACED);
//		ft_printf("Should not be here\n");
		status = sh_exec_wait(job, main, exec);
		tcsetpgrp(STDOUT_FILENO, main->pid);
		tcsetattr(STDOUT_FILENO, TCSADRAIN, &main->t_curr);
	}
	else
	{
		sh_exec_add_job(main, job);
		ft_printf("[%d] %d\n", job->num, job->pid);
	}
	return (status);
}

void	sh_exec_setpgid(bool bg, t_main *main)
{
	pid_t	pid;

	pid = getpid();
	setpgid(pid, pid);
	if (bg == 0)
	{
		tcsetpgrp(STDOUT_FILENO, pid);
		tcsetattr(STDOUT_FILENO, TCSADRAIN, &main->t_start);
	}
	else
		tcsetpgrp(STDOUT_FILENO, main->pid);
}

void	sh_signal_child(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}
/*
END OF NEW FILE
*/
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

void	sh_exit_code_check(t_exec *exec, int status)
{
	if (WIFEXITED(status) != 0)
	{
		exec->exit_s = WEXITSTATUS(status);
	}
	else
	{
		exec->exit_s = 1;
	}
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
//		sh_exec_setpgid(exec->bg, main);
//			ft_printf("CPID = %i\n", getpid());
			if (exec->redir)
				r_err = sh_redirects_hub(exec, main);
			if (r_err >= 0 && (((err = sh_exec_prog(exec, main, err_built)) != 0) ||
				main->alias_cont))
				sh_exec_print_error(err, main);
		}
		else
		{
			main->cpid = cpid;
//			setpgid(0, 0);
			status = sh_exec_job(main, exec);
//			waitpid(cpid, &status, 0);
//			sh_exit_code_check(exec, status);
//			main->cpid = -1;

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
/*
NEW FILE
*/
void	sh_gnu_init(t_main *main)
{
	pid_t	shell_pgid;

	signal (SIGINT, SIG_IGN);
	signal (SIGQUIT, SIG_IGN);
	signal (SIGTSTP, SIG_IGN);
	signal (SIGTTIN, SIG_IGN);
	signal (SIGTTOU, SIG_IGN);
	signal (SIGCHLD, SIG_IGN);
	shell_pgid = getpid();
	setpgid(shell_pgid, shell_pgid);
}

static void	sh_exec_job_state_assign(t_jobs *job, int state, int status)
{
	job->state = state;
	job->status = status;
//	ft_printf("job->cmd = %s, job->state = %i\n", job->cmd, job->state);
}


void		sh_exec_job_state_check(t_jobs *job)
{
	pid_t 	ret;
	int		status;

	ret = 0;
	status = 0;
	if (!(ret = waitpid(job->pid, &status, WNOHANG | WCONTINUED | WUNTRACED)))
		return ;
//	ft_printf("ret = %i\n", ret);
	if (ret == 0)
		return ;
//	ret = waitpid(job->pid, &status, WUNTRACED | WNOHANG);
//	ret = waitpid(job->pid, &status, WNOHANG | WCONTINUED | WUNTRACED);
//	ft_printf("ret = %i, Job->pid = %i\n",ret, job->pid);
	if (WIFSTOPPED(status))
	{
//		ft_printf("WIFSTOPPED\n");
		sh_exec_job_state_assign(job, STOPPED, WSTOPSIG(status));
	}
	else if (WIFEXITED(status))
	{
//		ft_printf("WIFEXITED\n");
		sh_exec_job_state_assign(job, DONE, WEXITSTATUS(status));
	}
	else if (ret == -1)
	{
//		ft_printf("ret = -1\n");
		sh_exec_job_state_assign(job, DONE, 0);
	}
	else if (WIFSIGNALED(status))
	{
//		ft_printf("WIFSIGNALED\n");
		sh_exec_job_state_assign(job, SIGNALED, WTERMSIG(status));
	}
	else
	{
//		ft_printf("ELSE\n");
		sh_exec_job_state_assign(job, RUNNING, 0);
	}
}

void		sh_exec_job_state(t_jobs *job)
{
	while (job)
	{
	//	ft_printf("*JOB STATE, job->cmd =%s, pid = %i, state = %i\n", job->cmd, job->pid, job->state);
		sh_exec_job_state_check(job);
		job = job->next;
	}
}

void	sh_exec_job_print_completed(t_main *main)
{
	t_jobs	*j;

	j = main->jobs;
	while (j)
	{
		if (j->state == DONE)
			ft_printf("[%d] Done %20s\n", j->num, j->cmd);
		j = j->next;
	}
}

void	sh_exec_job_del_completed(t_main *main)
{
	t_jobs	*j;
	t_jobs	*prev;

	j = main->jobs;
	if (!main->jobs)
		return ;
	if (j->state == DONE)
	{
		main->jobs = j->next;
		//sh_job_remove(j);
		sh_exec_job_del_completed(main);
	}
	else
	{
		prev = j;
		j = j->next;
		while (j)
		{
			if (j->state == DONE)
			{
				prev->next = j->next;
				//sh_job_remove(j);
				j = prev->next;
			}
			else
			{
				prev = j;
				j = j->next;
			}

		}
	}
}

/*
END OF NEW FILE
*/

void	sh_exec(t_main *main, t_exec *exec)
{
	// 	sh_exec_job_state(main->jobs);
	// 		sh_exec_job_print_completed(main);
	// sh_exec_job_del_completed(main);


	while (exec)
	{
		// if (exec->bg == false)//DELETE THIS PART! ONLY FOR TEST WHILE TREE NOT WORKIN
		// {
		// 	if (ft_strcmp(exec->argv[0], "jobs") != 0)
		// 		exec->bg = true;
		// }
		if (!main->vars)
			sh_get_vars_from_env(main);
		sh_gnu_init(main);
//		tcsetattr(main->fd, TCSANOW, &main->t_curr);
//		ft_printf("exec->&& = %i exec->|| = %i\n", exec->andif, exec->orif);
		if (exec->next && exec->next->pipe == true)
		{
			sh_exec_piped_commands(exec, main);
			exec = exec->next;
			while (exec && exec->pipe == true)
			{
				main->ex_code = exec->exit_s;
				exec = exec->next;
			}
		}
		else
		{
			if (!exec->argv)
				sh_check_variables(exec, main);
			sh_change_envvars_in_exec(main, exec);
			sh_standart_exec(exec, main);
			main->ex_code = exec->exit_s;
			exec = sh_or_if_and_if_check(exec);
//			exec = exec->next;
		}
		tcsetpgrp(STDOUT_FILENO, main->pid);
		tcsetattr(STDOUT_FILENO, TCSADRAIN, &main->t_curr);

//		
	}
	sh_exec_job_state(main->jobs);
	sh_exec_job_print_completed(main);
	sh_exec_job_del_completed(main);
	
//	tcsetattr(main->fd, TCSANOW, &main->t_curr);
}
