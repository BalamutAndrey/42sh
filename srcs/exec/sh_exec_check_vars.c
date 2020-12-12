/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_check_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:31:14 by geliz             #+#    #+#             */
/*   Updated: 2020/12/12 18:10:25 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
			ft_strdel(&name);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_strdel(&name);
	return (0);
}

void	sh_add_var_to_struct(t_main *main, char *str)
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
	new->env = 1;
	new->next = main->vars;
	main->vars = new;
}

void	sh_get_vars_from_env(t_main *main)
{
	int		i;

	i = 0;
	while (main->envp_curr[i])
	{
		sh_add_var_to_struct(main, main->envp_curr[i]);
		i++;
	}
}

void	sh_check_variables(t_exec *exec, t_main *main)
{
	int		i;

	if (!exec->vars)
		return ;
	if (!main->vars)
		sh_get_vars_from_env(main);
	i = 0;
	while (exec->vars[i])
	{
		sh_add_var_to_struct(main, exec->vars[i]);
		i++;
	}
}
