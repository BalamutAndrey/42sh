/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_andif_orif_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:20:13 by geliz             #+#    #+#             */
/*   Updated: 2021/02/01 20:21:44 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh_main.h>

t_exec	*sh_orif_check(t_exec *exec)
{
	t_exec	*tmp;

	tmp = exec;
	if (exec->exit_s != 0)
		return (exec->next);
	else
	{
		while (tmp)
		{
			if (!tmp->next)
				return (NULL);
			if (tmp->orif == true)
				tmp = tmp->next;
			else if (tmp->andif == true)
				return (tmp->next);
		}
		return (tmp);
	}
}

t_exec	*sh_andif_check(t_exec *exec)
{
	t_exec	*tmp;

	tmp = exec;
	if (exec->exit_s == 0)
	{
		return (exec->next);
	}
	else
	{
		while (tmp)
		{
			if (!tmp->next)
				return (NULL);
			else if (tmp->andif == true)
				tmp = tmp->next;
			else if (tmp->orif == true)
				return (tmp->next);
		}
		return (tmp);
	}
}

t_exec	*sh_or_if_and_if_check(t_exec *exec)
{
	if (!exec->next)
		return (NULL);
	if (exec->andif == false && exec->orif == false)
		return (exec->next);
	if (exec->andif == true)
		return (sh_andif_check(exec));
	if (exec->orif == true)
		return (sh_orif_check(exec));
	return (exec->next);
}
