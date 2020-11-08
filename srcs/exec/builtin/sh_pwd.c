/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:24:54 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:14:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_pwd(t_exec *exec, t_main *main)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	while (exec->argv[n] != NULL)
	{
		i++;
		n++;
	}
	if (i > 1)
	{
		ft_fprintf(main->fd, "21sh: pwd: too many arguments\n");
		sh_pwd_error(main);
	}
	else if (i == 1)
		sh_pwd_check_param(exec, main);
	else
		sh_pwd_print_dir(main, false);
}

void	sh_pwd_error(t_main *main)
{
	ft_fprintf(main->fd, "Usage: pwd [-L | -P]\n");
}

void	sh_pwd_check_param(t_exec *exec, t_main *main)
{
	if ((ft_strncmp(exec->argv[1], "-L", 3) == 0) ||
		(ft_strncmp(exec->argv[1], "--logical", 9) == 0))
	{
		sh_pwd_print_dir(main, false);
	}
	else if ((ft_strncmp(exec->argv[1], "-P", 3) == 0) ||
			(ft_strncmp(exec->argv[1], "--physical", 10) == 0))
	{
		sh_pwd_print_dir(main, true);
	}
	else
	{
		ft_fprintf(main->fd, "21sh: pwd: bad option: %s\n", exec->argv[1]);
		sh_pwd_error(main);
	}
}

void	sh_pwd_print_dir(t_main *main, bool param)
{
	char	*temp;
	int16_t	i;

	temp = NULL;
	if (param == false)
	{
		i = 0;
		while (main->envp_curr[i] != NULL)
		{
			if ((ft_strncmp(main->envp_curr[i], "PWD=", 4) == 0) && !temp)
				temp = sh_strsub(main->envp_curr[i], 4,
				ft_strlen(main->envp_curr[i]) - 4, main);
			i++;
		}
		if (temp != NULL)
		{
			ft_fprintf(STDOUT_FILENO, "%s\n", temp);
			ft_strdel(&temp);
		}
		else
			ft_fprintf(STDOUT_FILENO, "%s\n", main->dir);
	}
	else if (param == true)
		ft_fprintf(STDOUT_FILENO, "%s\n", main->dir);
}
