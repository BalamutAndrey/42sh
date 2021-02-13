/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:22:48 by eboris            #+#    #+#             */
/*   Updated: 2021/02/13 18:31:03 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_change_job_state(t_main *main)
{
	t_jobs	*j;

	j = main->jobs;
	while (j->pid != main->cpid)
		j = j->next;
	if (j)
		j->state = STOPPED;
}

void	sh_sig_ctrl_z(int a)
{
	extern t_main	*g_main;

	(void)a;
	if (g_main->cpid != -1)
	{
		tcsetattr(g_main->fd, TCSANOW, &g_main->t_curr);
		kill(g_main->cpid, SIGSTOP);
		ft_putstr_fd(tgetstr("do", NULL), g_main->fd);
		ft_putstr_fd(tgetstr("cr", NULL), g_main->fd);
		sh_exec_job(g_main, g_main->exec_curr);
		sh_change_job_state(g_main);
	}
}
