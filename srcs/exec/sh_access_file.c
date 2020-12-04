/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_access_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:35:21 by eboris            #+#    #+#             */
/*   Updated: 2020/11/29 14:35:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_run_access(char **str)
{
	struct stat	buff;

	if (!str)
		return (0);
	if ((sh_is_builtin(str[0]) == true) &&
		(sh_is_builtin_nofork(str[0]) == false))
		return (6);
	if ((sh_is_builtin(str[0]) == true) &&
		(sh_is_builtin_nofork(str[0]) == true))
		return (5);
	if (access(str[0], 0) != 0)
		return (1);
	if (access(str[0], 1) != 0)
		return (2);
	lstat(str[0], &buff);
	if (!(S_ISLNK(buff.st_mode)) && !(S_ISREG(buff.st_mode)))
		return (3);
	if (!(S_ISLNK(buff.st_mode)))
		stat(str[0], &buff);
	if ((buff.st_mode & S_IXUSR) || (buff.st_mode & S_IXGRP) ||
			(buff.st_mode & S_IXOTH))
		return (0);
	return (4);
}

bool	sh_is_builtin(char *str)
{
	if ((ft_strcmp(str, "exit") == 0) ||
		(ft_strcmp(str, "cd") == 0) ||
		(ft_strcmp(str, "echo") == 0) ||
		(ft_strcmp(str, "alias") == 0) ||
		(ft_strcmp(str, "env") == 0) ||
		(ft_strcmp(str, "setenv") == 0) ||
		(ft_strcmp(str, "unsetenv") == 0) ||
		(ft_strcmp(str, "pwd") == 0))
	{
		return (true);
	}
	return (false);
}

bool	sh_is_builtin_nofork(char *str)
{
	if ((ft_strcmp(str, "cd") == 0) ||
		(ft_strcmp(str, "exit") == 0) ||
		(ft_strcmp(str, "alias") == 0) ||
		(ft_strcmp(str, "setenv") == 0) ||
		(ft_strcmp(str, "unsetenv") == 0))
	{
		return (true);
	}
	return (false);
}
