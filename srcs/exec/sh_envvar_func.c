/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:25 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 17:04:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
	len = envvar->end - envvar->start;
	var = sh_strsub(envvar->str, envvar->start + 1, len - 1, main);
	var = sh_strjoin_arg(main, "%f %s", var, "=");
	return (var);
}

char	*sh_find_envvar_in_env(char **env, t_envvar *envvar, t_main *main)
{
	int		i;
	char	*pos;
	int		len;
	char	*var;

	i = 0;
	pos = NULL;
	var = sh_get_envvar_from_str(envvar, main);
	while (env[i])
	{
		if ((pos = ft_strnstr(env[i], var, ft_strlen(var))) != NULL)
		{
			len = ft_strlen(var);
			ft_strdel(&var);
			return (&pos[len]);
		}
		i++;
	}
	ft_strdel(&var);
	return (NULL);
}
