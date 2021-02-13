/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_func_envvar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:23:47 by eboris            #+#    #+#             */
/*   Updated: 2021/02/13 20:27:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_get_envvar_from_str(t_envvar *envvar, t_main *main)
{
	char	*var;
	int		len;

	if (envvar->type == 0)
	{
		var = sh_strdup("HOME=", main);
		return (var);
	}
	if (envvar->type == 2)
	{
		var = sh_env_cont_with_cond(envvar, main);
		return (var);
	}
	len = envvar->end - envvar->start;
	var = sh_strsub(envvar->str, envvar->start + 1, len - 1, main);
	var = sh_strjoin_arg(main, "%f %s", var, "=");
	return (var);
}

char	*sh_find_envvar_in_vars(t_main *main, t_envvar *envvar, int *fl)
{
	char	*var;
	t_vars	*tmp;

	*fl = 0;
	tmp = main->vars;
	var = sh_get_envvar_from_str(envvar, main);
	if (!var)
	{
		*fl = 1;
		return (ft_itoa(main->ex_code));
	}
	while (tmp)
	{
		if (ft_strcmp(var, tmp->name) == 0)
		{
			ft_strdel(&var);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	ft_strdel(&var);
	return (NULL);
}
