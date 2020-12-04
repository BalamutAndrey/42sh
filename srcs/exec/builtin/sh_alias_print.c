/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:12:17 by eboris            #+#    #+#             */
/*   Updated: 2020/11/29 15:50:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias_print(t_main *main)
{
	char	*fin;
	t_alias	*temp;

	fin = sh_strnew(1, main);
	temp = main->alias;
	while (temp)
	{
		fin = sh_strjoin_arg(
			main, "%f %s %s %s %s", fin, temp->name, "=", temp->command, "\n");
		temp = temp->next;
	}
	return (fin);
}

char	*sh_alias_print_one(t_main *main, char *name)
{
	char	*fin;
	t_alias	*temp;

	fin = sh_strnew(1, main);
	temp = main->alias;
	while (temp)
	{
		if (ft_strcmp(name, temp->name) == 0)
		{
			fin = sh_strjoin_arg(
			main, "%f %s %s %s %s", fin, temp->name, "=", temp->command, "\n");
			temp = NULL;
		}
		else
			temp = temp->next;
	}
	return (fin);
}
