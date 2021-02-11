/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:25 by geliz             #+#    #+#             */
/*   Updated: 2021/02/01 17:42:27 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_search_condition_more(char *tmp)
{
	int		type;

	type = 0;
	if (ft_strnstr(tmp, ":+", 2))
		type = 7;
	else if (ft_strchr(tmp, '+'))
		type = 8;
	else if (ft_strnstr(tmp , "##", 2))
		type = 9;
	else if (ft_strchr(tmp, '#'))
		type = 10;
	else if (ft_strnstr(tmp, "%%", 2))
		type = 11;
	else if (ft_strchr(tmp, '%'))
		type = 12;
	return (type);
}


int		sh_search_condition(t_envvar *envvar, t_main *main)
{
	char	*tmp;
	int		type;

	type = 0;
	tmp = sh_strsub(envvar->str, envvar->start, envvar->end - envvar->start, main);
	if (ft_strcmp(tmp, "${?}") == 0)
		type = -1;
	else if (ft_strnstr(tmp, ":-", 2))
		type = 1;
	else if (ft_strchr(tmp, '-'))
		type = 2;
	else if (ft_strnstr(tmp, ":=", 2))
		type = 3;
	else if (ft_strchr(tmp, '='))
		type = 4;
	else if (ft_strnstr(tmp, ":?", 2))
		type = 5;
	else if (ft_strchr(tmp, '?'))
		type = 6;
	else
		type = sh_search_condition_more(tmp);
	ft_strdel(&tmp);
	return (type);
}

char	*sh_env_cont_with_cond(t_envvar *envvar, t_main *main)
{
	int		len;
	char	*var;
	int		cond;

	cond = sh_search_condition(envvar, main);
	if (cond == -1)
	{
		return (NULL);
	}
	if (cond == 0)
	{
		len = envvar->end - envvar->start - 2;
		var = sh_strsub(envvar->str, envvar->start + 2, len - 1, main);
		var = sh_strjoin_arg(main, "%f %s", var, "=");
	}
	else
	{
		var = NULL;
	}
	return (var);
}

void	sh_envvar_add_shift_to_struct(t_envvar *envvar, char *new_str,
	int shift)
{
	envvar->next->str = new_str;
	envvar->next->start += shift;
	envvar->next->end += shift;
}

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

char	*sh_find_envvar_in_vars(t_main *main, t_envvar *envvar)
{
	char	*var;
	t_vars	*tmp;

	tmp = main->vars;
	var = sh_get_envvar_from_str(envvar, main);
	if (!var)
		return (ft_itoa(main->ex_code));
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
