/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:43:03 by geliz             #+#    #+#             */
/*   Updated: 2021/02/06 16:52:32 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_unalias_one_delete_cont(t_alias *al)
{
	ft_strdel(&al->name);
	ft_strdel(&al->command);
	al->next = NULL;
	free(al);
}

int		sh_unalias_one(char *str, t_main *main)
{
	t_alias *al;
	t_alias *prev;

	al = main->alias;
	prev = NULL;
	while (al)
	{
		if (ft_strcmp(al->name, str) == 0)
		{
			if (!prev)
				main->alias = al->next;
			else
				prev->next = al->next;
			sh_unalias_one_delete_cont(al);
			al = NULL;
			return (1);
		}
		else
		{
			prev = al;
			al = al->next;
		}
	}
	return (0);
}

char	*sh_builtin_unalias(t_exec *exec, t_main *main)
{
	int		i;
	char	*ret;

	i = 1;
	ret = NULL;
	if (!exec->argv[1])
		return (NULL);
	if (ft_strcmp(exec->argv[i], "-a") == 0)
		sh_remove_alias(main);
	else
	{
		while (exec->argv[i])
		{
			if (sh_unalias_one(exec->argv[i], main) == 0)
				ret = sh_strjoin_arg(main, "%f %s %s %s", ret,
				"42sh: unalias: ", exec->argv[i], " :not found\n");
			i++;
		}
	}
	return (ret);
}
