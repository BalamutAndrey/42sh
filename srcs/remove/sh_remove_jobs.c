/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_jobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:38:27 by geliz             #+#    #+#             */
/*   Updated: 2021/02/12 17:11:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_jobs(t_main *main)
{
	t_jobs	*tmp;
	t_jobs	*nxt;

	tmp = main->jobs;
	while (tmp)
	{
		nxt = tmp->next;
		sh_job_remove(tmp);
		tmp = nxt;
	}
	main->jobs = NULL;
}
