/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:39:15 by geliz             #+#    #+#             */
/*   Updated: 2021/02/09 00:52:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
//		sh_exec_delete_job(tmp);
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
				//sh_exec_delete_job(tmp);
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
