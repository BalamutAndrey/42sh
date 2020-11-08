/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:14:16 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 14:44:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_exec(t_main *main)
{
	t_exec	*temp;

	if (main->exec_first != NULL)
	{
		temp = main->exec_first;
		while (temp != NULL)
		{
			main->exec_first = temp->next;
			sh_remove_exec_exec(temp);
			temp = main->exec_first;
		}
		main->exec_first = NULL;
	}
	main->exec_curr = NULL;
}

void	sh_remove_exec_exec(t_exec *temp)
{
	if (temp)
	{
		if (temp->cmd != NULL)
			ft_strdel(&temp->cmd);
		sh_remove_argv(temp->argv);
		temp->argv = NULL;
		sh_remove_redirect(temp->redir);
		temp->redir = NULL;
		sh_remove_envvar(temp->envvar_first);
		temp->envvar = NULL;
		temp->envvar_curr = NULL;
		free(temp);
	}
}

void	sh_remove_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			ft_strdel(&argv[i]);
			i++;
		}
		free(argv);
		argv = NULL;
	}
}

void	sh_remove_redirect(t_redirect *redir)
{
	t_redirect	*temp;

	if (redir != NULL)
	{
		temp = redir;
		while (temp)
		{
			redir = temp->next;
			if (temp->filename != NULL)
				ft_strdel(&temp->filename);
			sh_remove_envvar(temp->envvar_first);
			temp->envvar = NULL;
			temp->envvar_curr = NULL;
			free(temp);
			temp = redir;
		}
	}
}
