/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_fg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:53:34 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:37:25 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_fg_action(t_main *main, t_jobs *job, t_exec *exec)
{
	tcsetpgrp(STDOUT_FILENO, job->pid);
	kill(job->pid, SIGCONT);
	sh_exec_wait(job, main, exec);
	tcsetpgrp(STDOUT_FILENO, main->pid);
	tcsetattr(STDOUT_FILENO, TCSADRAIN, &main->t_curr);
}

char	*sh_builtin_fg_current(t_main *main, char *number, t_exec *exec)
{
	t_jobs	*job;
	int		num;

	job = main->jobs;
	if (ft_strcmp(number, "+") == 0)
	{
		while (job && job->sign != '+')
			job = job->next;
	}
	else
	{
		num = ft_atoi(number);
		while (job && job->num != num)
			job = job->next;
	}
	if (!job)
		return (sh_strdup("fg: no such job\n", main));
	else
		sh_builtin_fg_action(main, job, exec);
	return (NULL);
}

int		sh_builtin_fg_check_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*sh_builtin_fg(t_exec *exec, t_main *main)
{
	char	*ret;

	ret = NULL;
	if (!main->jobs)
		return (sh_strdup("fg: no such job\n", main));
	if (!exec->argv[1])
		ret = sh_builtin_fg_current(main, "+", exec);
	else if (exec->argv[2])
		return (sh_strdup("fg: Too many arguments\n", main));
	else if (sh_builtin_fg_check_num(exec->argv[1]) != 0)
		return (sh_strdup("fg: no such job\n", main));
	else if (exec->argv[1])
		ret = sh_builtin_fg_current(main, exec->argv[1], exec);
	return (ret);
}
