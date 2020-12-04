/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:14:01 by eboris            #+#    #+#             */
/*   Updated: 2020/12/04 16:37:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias_arg(t_exec *exec, t_main *main)
{
	char	*fin;

	fin = NULL;
	if (ft_strchr(exec->argv[1], '=') == NULL)
	{
		sh_alias_print_one(main, exec->argv[1]);
	}
	else
	{
		main->alias = sh_alias_new(main, exec->argv[1]);
	}
	return (fin);
}

t_alias	*sh_alias_new(t_main *main, char *str)
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
	new->next = NULL;
	return (new);
}

void	sh_alias_replace(t_main *main, char *str)
{
	(void)main;
	(void)str;
}
