/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:19:44 by geliz             #+#    #+#             */
/*   Updated: 2020/12/13 18:12:44 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_export_add_env(t_main *main, t_vars *var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (main->envp_curr[i])
		i++;
	new_env = sh_memalloc(sizeof(char*) * (i + 2), main);
	new_env[i + 1] = NULL;
	new_env[i] = sh_strjoin_arg(main, "%s%s", var->name, var->value);
	while (--i != -1)
	{
		new_env[i] = sh_strdup(main->envp_curr[i], main);
	}
	sh_remove_envp_curr(main);
	main->envp_curr = new_env;
	if (ft_strcmp(var->name, "PATH=") == 0)
		sh_path(main);
}

void	sh_builtin_export_var(t_main *main, char *str)
{
	t_vars	*tmp;

	tmp = main->vars;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, str, ft_strlen(str)) == 0)
		{
			if (tmp->env == 1)
				return ;
			tmp->env = 1;
			sh_builtin_export_add_env(main, tmp);
		}
		tmp = tmp->next;
	}
}

void	sh_builtin_export(t_exec *exec, t_main *main)
{
	int		i;

	i = 1;
	while (exec->argv[i])
	{
		sh_builtin_export_var(main, exec->argv[i]);
		i++;
	}
}
