/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:38:40 by geliz             #+#    #+#             */
/*   Updated: 2020/12/13 18:24:46 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_change_vars_after_setenv(t_main *main, char *str, int new)
{
	t_vars	*tmp;
	int		i;

	if (new == 1)
	{
		sh_add_var_to_struct(main, str, 1);
		return ;
	}
	tmp = main->vars;
	i = 0;
	while (str[i] != '=')
		i++;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, str, (i + 1)) == 0)
		{
			ft_strdel(&tmp->value);
			tmp->value = sh_strdup(&str[i + 2], main);
			return ;
		}
		tmp = tmp->next;
	}
}

void	sh_builtin_setenv_change_env(t_exec *exec, t_main *main, char *tmp,
		int i)
{
	tmp = sh_strjoin_arg(main, "%f %s", tmp, exec->argv[2]);
	ft_strdel(&main->envp_curr[i]);
	main->envp_curr[i] = tmp;
	sh_builtin_change_vars_after_setenv(main, tmp, 0);
	if (ft_strncmp(main->envp_curr[i], "PATH=", 5) == 0)
		sh_path(main);
}

void	sh_builtin_setenv_new_env(t_exec *exec, t_main *main, char *tmp, int i)
{
	char	**new_env;

	new_env = sh_memalloc(sizeof(char*) * (i + 2), main);
	new_env[i + 1] = NULL;
	tmp = sh_strjoin_arg(main, "%f %s", tmp, exec->argv[2]);
	new_env[i] = tmp;
	sh_builtin_change_vars_after_setenv(main, tmp, 1);
	while (--i != -1)
	{
		new_env[i] = sh_strdup(main->envp_curr[i], main);
	}
	sh_remove_envp_curr(main);
	main->envp_curr = new_env;
	if (ft_strncmp(tmp, "PATH=", 5) == 0)
		sh_path(main);
}

char	*sh_builtin_setenv_env_find(t_exec *exec, t_main *main)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!exec->argv[1])
		return (sh_strdup("21sh: setenv: usage \"setenv VAR VALUE\"\n", main));
	if (ft_isalpha(exec->argv[1][0]) != 1)
	{
		return (sh_strdup(
			"21sh: setenv: Variable name must begin with a letter.\n", main));
	}
	while (exec->argv[i])
		i++;
	if (i >= 3 && exec->argv[3])
		return (sh_strdup("21sh: setenv: Too many arguments.\n", main));
	i = 0;
	tmp = sh_strjoin_arg(main, "%s %s", exec->argv[1], "=");
	while (main->envp_curr[i] && ft_strncmp(tmp, main->envp_curr[i],
		ft_strlen(tmp)) != 0)
		i++;
	if (!main->envp_curr[i])
		sh_builtin_setenv_new_env(exec, main, tmp, i);
	else
		sh_builtin_setenv_change_env(exec, main, tmp, i);
	return (NULL);
}

char	*sh_builtin_setenv(t_exec *exec, t_main *main)
{
	char	*err;

	err = sh_builtin_setenv_env_find(exec, main);
	return (err);
}
