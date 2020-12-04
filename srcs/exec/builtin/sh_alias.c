/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:55:10 by eboris            #+#    #+#             */
/*   Updated: 2020/11/29 14:43:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias(t_exec *exec, t_main *main)
{
	int		i;
	int		n;
	char	*fin;

	i = 0;
	n = 1;
	fin = NULL;
	if (!exec->argv[1])
	{
		fin = sh_alias_print(main);
		return (fin);
	}
	while (exec->argv[n] != NULL)
	{
		i++;
		n++;
	}
	if (i > 1)
		fin = sh_strdup(
		"42sh: alias: too many arguments\n\
Usage: alias [alias-name[=string]]\n", main);
	else
		fin = sh_alias_arg(exec, main);
	return (fin);
}
