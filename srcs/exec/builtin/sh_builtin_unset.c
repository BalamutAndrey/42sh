/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:20:15 by geliz             #+#    #+#             */
/*   Updated: 2020/12/13 18:24:00 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_unset_var(t_main *main, char *str)
{
	t_vars	*tmp;
	t_vars	*prev;

	prev = NULL;
	tmp = main->vars;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, str, ft_strlen(str)) == 0)
		{
			if (!prev)
				main->vars = tmp->next;
			else
				prev->next = tmp->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->value);
			tmp->next = NULL;
			free(tmp);
			tmp = NULL;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	sh_builtin_unset(t_exec *exec, t_main *main)
{
	int		i;

	i = 1;
	while (exec->argv[i])
	{
		sh_builtin_unset_var(main, exec->argv[i]);
		i++;
	}
}
