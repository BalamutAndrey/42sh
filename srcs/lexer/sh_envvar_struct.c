/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:10:52 by geliz             #+#    #+#             */
/*   Updated: 2020/12/19 16:03:47 by geliz            ###   ########.fr       */
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

int		sh_find_end_of_envvar(t_main *main, t_token *token, int i,
	t_envvar *new)
{
	if (token->content[i] == '{')
	{
		new->type = 2;
		while (token->content[i])
		{
			if (token->content[i] == '}')
				return (i + 1);
			i++;
		}
	}
	else
	{
		while (ft_isalnum(token->content[i]) == 1)
			i++;
		return (i);
	}
	(void)main;
	return (i);
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
	i = sh_find_end_of_envvar(main, token, i, new);
	new->end = i;
	return (i);
}
