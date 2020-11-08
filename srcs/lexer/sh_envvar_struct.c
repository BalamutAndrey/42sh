/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:10:52 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 17:14:51 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_delete_envvars(t_envvar *envvar)
{
	t_envvar	*tmp;

	while (envvar)
	{
		tmp = envvar->next;
		envvar->str = NULL;
		envvar->next = NULL;
		free(envvar);
		envvar = tmp;
	}
}

int		sh_add_envvar(int type, int i, t_main *main, t_token *token)
{
	t_envvar	*new;

	if (!token->envvar)
	{
		token->envvar = sh_memalloc(sizeof(t_envvar), main);
		new = token->envvar;
	}
	else
	{
		new = token->envvar;
		while (new->next)
			new = new->next;
		new->next = sh_memalloc(sizeof(t_envvar), main);
		new = new->next;
	}
	new->next = NULL;
	new->type = type;
	new->start = i;
	new->str = NULL;
	i++;
	while (ft_isalpha(token->content[i]) == 1 ||
		ft_isalnum(token->content[i]) == 1)
		i++;
	new->end = i;
	return (i);
}
