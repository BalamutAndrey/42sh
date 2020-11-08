/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:53:48 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:17:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_path_add(t_main *main, t_exec *temp)
{
	if (temp->argv != NULL && temp->argv[0][0] != '\0')
	{
		if (temp->argv[0][0] == '.')
			sh_run_write_string_point(main, temp);
		else if (temp->argv[0][0] == '~')
			sh_run_write_string_home(main, temp);
		else if ((temp->argv[0][0] != '/') &&
			(sh_is_builtin(temp->argv[0]) == false))
			sh_find_path(main, temp);
	}
}

void	sh_run_write_string_point(t_main *main, t_exec *temp)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(main->dir);
	str1 = ft_strdup("/");
	str2 = ft_strsdup(str2, str1);
	str1 = ft_strdup(temp->argv[0]);
	ft_strdel(&temp->argv[0]);
	temp->argv[0] = ft_strsdup(str2, str1);
}

void	sh_run_write_string_home(t_main *main, t_exec *temp)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(temp->argv[0]);
	str2 = ft_strmancpy(str2, 1);
	str1 = ft_strdup(main->home);
	ft_strdel(&temp->argv[0]);
	temp->argv[0] = ft_strsdup(str1, str2);
}

void	sh_find_path(t_main *main, t_exec *exec)
{
	t_path	*temp;
	char	*str1;

	temp = main->path;
	while (temp)
	{
		str1 = sh_strjoin_arg(main, "%s %s %s", temp->path, "/", exec->argv[0]);
		if (sh_run_access(&str1) == 0)
		{
			ft_strdel(&exec->argv[0]);
			exec->argv[0] = ft_strdup(str1);
			temp = NULL;
		}
		else
		{
			temp = temp->next;
		}
		ft_strdel(&str1);
	}
}
