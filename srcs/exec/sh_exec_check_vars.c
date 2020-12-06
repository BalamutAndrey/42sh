/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_check_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:31:14 by geliz             #+#    #+#             */
/*   Updated: 2020/12/06 18:06:42 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_vars	*sh_add_var_to_struct(t_main *main, char *str)
{
	t_vars	*new;
	int		i;

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
