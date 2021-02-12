/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:25 by geliz             #+#    #+#             */
/*   Updated: 2021/02/12 15:24:57 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_search_condition_more(char *tmp)
{
	int	type;

	type = 0;
	if (ft_strnstr(tmp, ":+", 2))
		type = 7;
	else if (ft_strchr(tmp, '+'))
		type = 8;
	else if (ft_strnstr(tmp, "##", 2))
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
	tmp = sh_strsub(
		envvar->str, envvar->start, envvar->end - envvar->start, main);
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
