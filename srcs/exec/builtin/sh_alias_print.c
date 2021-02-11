/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:12:17 by eboris            #+#    #+#             */
/*   Updated: 2021/01/08 16:18:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias_err_get(char *str, t_main *main)
{
	char	*ret;

	ret = sh_strjoin_arg(main, "%s %s %s", "42sh: alias: ",
		str, ": not found\n");
	return (ret);
}

void	sh_alias_print(t_main *main)
{
	char	*fin;
	t_alias	*temp;

	fin = NULL;
	temp = main->alias;
	while (temp)
	{
		fin = sh_strjoin_arg(main, "%f %s %s %s %s", fin,
			temp->name, "='", temp->command, "'\n");
		temp = temp->next;
	}
	if (fin)
		main->alias_cont = fin;
}

void	sh_alias_print_one(t_main *main, char *name)
{
	char	*fin;
	t_alias	*temp;

	fin = NULL;
	temp = main->alias;
	while (temp)
	{
		if (ft_strcmp(name, temp->name) == 0)
		{
			fin = sh_strjoin_arg(main, "%f %s %s %s %s", fin,
				temp->name, "='", temp->command, "'\n");
			temp = NULL;
		}
		else
			temp = temp->next;
	}
	if (fin)
		main->alias_cont = sh_strjoin_arg(main, "%f %f", main->alias_cont, fin);
	else
		main->alias_error = sh_strjoin_arg(main,
			"%f %f", main->alias_error, sh_alias_err_get(name, main));
}
