/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jobs_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:57:40 by geliz             #+#    #+#             */
/*   Updated: 2021/02/08 22:57:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
