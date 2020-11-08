/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:49:36 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:04:03 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_env_replace(t_main *new, char *whats, char *to)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(whats);
	if (len == 0)
		return (0);
	i = -1;
	temp = ft_strdup("=");
	temp = ft_strsdup(whats, temp);
	while (new->envp_curr[++i] != NULL)
	{
		if (ft_strncmp(new->envp_curr[i], temp, len + 1) == 0)
		{
			ft_strdel(&new->envp_curr[i]);
			whats = ft_strdup(temp);
			new->envp_curr[i] = ft_strsdup(whats, to);
			ft_strdel(&temp);
			return (1);
		}
	}
	sh_env_replace_new(new, temp, to);
	return (1);
}

void	sh_env_replace_new(t_main *new, char *whats, char *to)
{
	char	**env;
	char	*temp;
	int		i;
	int		n;

	i = 0;
	n = sh_env_len(new);
	env = malloc(sizeof(char *) * (n + 2));
	while (new->envp_curr[i] != NULL)
	{
		env[i] = ft_strdup(new->envp_curr[i]);
		i++;
	}
	temp = ft_strdup(whats);
	env[i] = ft_strsdup(whats, to);
	env[i + 1] = NULL;
	if (new->envp_curr)
		sh_env_remove(new);
	new->envp_curr = env;
	ft_strdel(&temp);
}

void	sh_env_remove(t_main *new)
{
	int	i;

	i = 0;
	while (new->envp_curr[i] != NULL)
	{
		ft_strdel(&new->envp_curr[i]);
		i++;
	}
	free(new->envp_curr);
	new->envp_curr = NULL;
}

int		sh_env_len(t_main *new)
{
	int	i;

	i = 0;
	while (new->envp_curr[i] != NULL)
		i++;
	return (i);
}
