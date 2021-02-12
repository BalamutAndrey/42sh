/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:17:24 by eboris            #+#    #+#             */
/*   Updated: 2021/02/12 15:17:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_set_pipes_exit_s(t_exec *exec, t_main *main)
{
	while (exec && exec->pipe == true)
	{
		main->ex_code = exec->exit_s;
		exec = exec->next;
	}
}

void	sh_exec_jobs_fin(t_main *main)
{
	sh_exec_job_state(main->jobs);
	sh_exec_job_print_completed(main);
	sh_exec_job_del_completed(main);
	main->bg = false;
}

void	sh_exec_bg_check(t_exec *exec, t_main *main)
{
	if (exec && !exec->next && main->bg == true)
		exec->bg = true;
}
