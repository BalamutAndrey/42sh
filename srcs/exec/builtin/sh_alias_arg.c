/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:14:01 by eboris            #+#    #+#             */
/*   Updated: 2021/01/08 16:26:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias_arg(t_exec *exec, t_main *main)
{
	char	*fin;
	char	*err;
	int		i;

	fin = NULL;
	err = NULL;
	i = 1;
	while (exec->argv[i])
	{
		if (ft_strchr(exec->argv[i], '='))
			sh_alias_new(main, exec->argv[i]);
		else
		{
			sh_alias_print_one(main, exec->argv[i]);
			if (main->alias_error)
				err = main->alias_error;
			// else
			// 	fin = sh_strjoin_arg(main, "%f %f", fin, tmp);
		}
		i++;
	}
/*	if (err)
	{
		ft_fprintf(STDERR_FILENO, "%s", err);
		ft_strdel(&err);
	}*/
	return (err);
}

void	sh_alias_new(t_main *main, char *str)
{
	t_alias	*new;
	char	*temp;
	int		i;

	i = 0;
	temp = sh_strdup(str, main);
	new = sh_memalloc(sizeof(t_alias), main);
	while (str[i] != '=')
	{
		i++;
	}
	new->name = ft_strmbncpy(temp, i);
	new->command = ft_strmancpy(temp, i + 1);
	new->recurs = 0;
	new->next = main->alias;
	main->alias = new;
	sh_alias_replace(main, new->name);

//	main->alias_end->next = new;
//	main->alias_end = new;
//	return (new);
}

void	sh_alias_replace(t_main *main, char *str)
{
	t_alias	*tmp;
	t_alias	*prev;

	tmp = main->alias->next;
	prev = main->alias;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
		{
			prev->next = tmp->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->command);
			tmp->next = NULL;
			free(tmp);
			tmp = NULL;
		}
		prev = tmp;
		if (tmp)
			tmp = tmp->next;
	}
}
