/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_in_redirs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:30 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 18:17:20 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_change_envvars_in_redir_struct(t_main *main, t_envvar *envvar)
{
	char	*ret;
	char	*env_cont;
	char	*before_var;
	char	*after_var;

	before_var = NULL;
	after_var = NULL;
	env_cont = sh_find_envvar_in_env(main->envp_curr, envvar, main);
	envvar->type = ft_strlen(env_cont) - (envvar->end - envvar->start);
	if (envvar->start > 0)
		before_var = sh_strsub(envvar->str, 0, envvar->start, main);
	if (envvar->end < (int)ft_strlen(envvar->str))
		after_var = sh_strsub(envvar->str, envvar->end, ft_strlen(envvar->str) -
			envvar->end, main);
	ret = sh_strjoin_arg(main, "%f %s %f", before_var, env_cont, after_var);
	return (ret);
}

void	sh_envvar_change_redir_cont(t_redirect *redir, char *new_str)
{
	ft_strdel(&redir->filename);
	redir->filename = new_str;
	new_str = NULL;
}

void	sh_change_envvars_in_redirs(t_main *main, t_redirect *redir)
{
	char	*new_str;
	int		shift;

	shift = 0;
	while (redir->envvar)
	{
		new_str = sh_change_envvars_in_redir_struct(main, redir->envvar);
		sh_envvar_change_redir_cont(redir, new_str);
		if (redir->envvar->next)
		{
			shift += redir->envvar->type;
			sh_envvar_add_shift_to_struct(redir->envvar, new_str, shift);
		}
		redir->envvar = redir->envvar->next;
	}
}
