/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:52:50 by geliz             #+#    #+#             */
/*   Updated: 2021/02/07 18:26:32 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_builtin_jobs_get_status(int state)
{
	if (state == 0)
		return ("Running");
	else if (state == 1)
		return ("Stopped");
	else if (state == 2)
		return ("Signaled");
	else if (state == 3)
		return ("Error");
	else if (state == 4)
		return ("Done");
	return (NULL);
}

void	sh_builtin_jobs_print(t_jobs *job)
{
	while (job)
	{
		ft_printf("[%d]%c %5d %-20s%s\n", job->num, job->sign, job->pid,
			sh_builtin_jobs_get_status(job->state), job->cmd);
		job = job->next;
	}
}

void	sh_builtin_jobs(t_exec *exec, t_main *main)
{
	sh_exec_job_state(main->jobs);
	sh_exec_jobs_put_signes(main);
//оно умеет работать с аргументами, но я это на данный момент проигнорирую,
//нужно общий принцип реализовать
	sh_builtin_jobs_print(main->jobs);
	sh_exec_job_del_completed(main);
}