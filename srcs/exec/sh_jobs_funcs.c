/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jobs_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:48:48 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:34:27 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_job_remove(t_jobs **job)
{
	char	*rm;

	if (job && *job)
	{
		rm = (*job)->cmd;
		ft_strdel(&rm);
		free(*job);
		*job = NULL;
	}
}

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
