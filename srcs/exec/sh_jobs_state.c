/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jobs_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:50:54 by geliz             #+#    #+#             */
/*   Updated: 2021/02/08 23:03:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_job_state_assign(t_jobs *job, int state, int status)
{
	job->state = state;
	job->status = status;
}

void	sh_exec_job_state_check(t_jobs *job)
{
	pid_t	ret;
	int		status;

	ret = 0;
	status = 0;
	if (!(ret = waitpid(job->pid, &status, WNOHANG | WCONTINUED | WUNTRACED)))
		return ;
	if (ret == 0)
		return ;
	if (WIFSTOPPED(status))
		sh_exec_job_state_assign(job, STOPPED, WSTOPSIG(status));
	else if (WIFEXITED(status))
		sh_exec_job_state_assign(job, DONE, WEXITSTATUS(status));
	else if (ret == -1)
		sh_exec_job_state_assign(job, DONE, 0);
	else if (WIFSIGNALED(status))
		sh_exec_job_state_assign(job, SIGNALED, WTERMSIG(status));
	else
		sh_exec_job_state_assign(job, RUNNING, 0);
}

void	sh_exec_job_state(t_jobs *job)
{
	while (job)
	{
		sh_exec_job_state_check(job);
		job = job->next;
	}
}

void	sh_jobs_check_not_first(t_jobs *j)
{
	t_jobs	*prev;

	prev = j;
	j = j->next;
	while (j)
	{
		if (j->state == DONE)
		{
			prev->next = j->next;
			sh_job_remove(j);
			j = prev->next;
		}
		else
		{
			prev = j;
			j = j->next;
		}
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
		sh_job_remove(j);
		sh_exec_job_del_completed(main);
	}
	else
	{
		sh_jobs_check_not_first(j);
	}
}
