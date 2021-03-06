/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_envvar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:48:13 by eboris            #+#    #+#             */
/*   Updated: 2020/12/13 15:24:21 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_vars(t_main *main)
{
	t_vars	*tmp;
	t_vars	*vars;

	vars = main->vars;
	if (vars != NULL)
	{
		tmp = vars;
		while (tmp)
		{
			vars = tmp->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->value);
			tmp->next = NULL;
			free(tmp);
			tmp = vars;
		}
	}
	main->vars = NULL;
}

void	sh_remove_envvar(t_envvar *envvar)
{
	t_envvar	*temp;

	if (envvar != NULL)
	{
		temp = envvar;
		while (temp != NULL)
		{
			envvar = temp->next;
			temp->str = NULL;
			temp->next = NULL;
			free(temp);
			temp = envvar;
		}
	}
}
