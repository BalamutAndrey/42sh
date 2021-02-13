/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_jobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:38:27 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 18:37:22 by geliz            ###   ########.fr       */
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
		sh_job_remove(&tmp);
		tmp = nxt;
	}
	main->jobs = NULL;
}
