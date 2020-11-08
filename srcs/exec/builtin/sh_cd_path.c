/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:30:04 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 14:51:59 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_home_dir(t_exec *exec, t_main *main, int p)
{
	char	*fin;
	char	*temp;

	fin = ft_strmancpy(exec->argv[p], 1);
	temp = sh_strdup(main->home, main);
	exec->argv[p] = ft_strsdup(temp, fin);
}

void	sh_prev_dir(t_exec *exec, t_main *main, int p)
{
	int		i;
	char	*fin;

	i = 0;
	fin = NULL;
	while (main->envp_curr[i] != NULL)
	{
		if ((ft_strncmp(main->envp_curr[i], "OLDPWD=", 7) == 0) && fin == NULL)
		{
			fin = ft_strdup(main->envp_curr[i]);
			fin = ft_strmancpy(fin, 7);
		}
		i++;
	}
	if (fin == NULL)
	{
		fin = ft_strdup(main->home);
	}
	ft_strdel(&exec->argv[p]);
	exec->argv[p] = fin;
}

void	sh_no_root_dir(t_exec *exec, t_main *main, int p)
{
	char	*fin;
	char	*temp;
	char	*temp2;

	temp = ft_strdup("/");
	temp2 = ft_strdup(main->dir);
	temp = ft_strsdup(temp2, temp);
	fin = ft_strsdup(temp, exec->argv[p]);
	exec->argv[p] = fin;
}
