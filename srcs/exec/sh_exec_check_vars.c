/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_check_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:31:14 by geliz             #+#    #+#             */
/*   Updated: 2021/01/06 15:41:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_change_current_env(t_main *main, t_vars *vars)
{
	int		i;

	i = 0;
	while (main->envp_curr[i])
	{
		if (ft_strncmp(main->envp_curr[i], vars->name,
			ft_strlen(vars->name)) == 0)
		{
			ft_strdel(&main->envp_curr[i]);
			main->envp_curr[i] = sh_strjoin_arg(main, "%s%s", vars->name,
				vars->value);
			if (ft_strncmp(main->envp_curr[i], "PATH=", 5) == 0)
				sh_path(main);
			return ;
		}
		i++;
	}
}

int		sh_check_exist_var(t_main *main, char *str)
{
	char	*name;
	int		i;
	t_vars	*tmp;

	i = 0;
	tmp = main->vars;
	while (str[i] != '=')
		i++;
	name = sh_strsub(str, 0, (i + 1), main);
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
		{
			ft_strdel(&tmp->value);
			tmp->value = sh_strdup((ft_strchr(str, '=') + 1), main);
			if (tmp->env == 1)
				sh_change_current_env(main, tmp);
			ft_strdel(&name);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_strdel(&name);
	return (0);
}

void	sh_add_var_to_struct(t_main *main, char *str, int type)
{
	t_vars	*new;
	int		i;

	if (sh_check_exist_var(main, str) == 1)
		return ;
	new = sh_memalloc(sizeof(t_vars), main);
	i = 0;
	while (str[i] != '=')
		i++;
	new->name = sh_strsub(str, 0, (i + 1), main);
	new->value = sh_strdup((ft_strchr(str, '=') + 1), main);
	new->env = type;
	new->next = main->vars;
	main->vars = new;
}

void	sh_get_vars_from_env(t_main *main)
{
	int		i;

	i = 0;
	while (main->envp_curr[i])
	{
		sh_add_var_to_struct(main, main->envp_curr[i], 1);
		i++;
	}
}

void	sh_check_variables(t_exec *exec, t_main *main)
{
	int		i;

	if (!main->vars)
		sh_get_vars_from_env(main);
	if (!exec->vars || (exec->argv && (ft_strcmp(exec->argv[0], "alias") == 0)))
		return ;
	i = 0;
	while (exec->vars[i])
	{
		sh_add_var_to_struct(main, exec->vars[i], 0);
		i++;
	}
}
