/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_envvar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:05:40 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:17:33 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void		sh_exec_struct_write_envvar(t_node *node, t_exec *exec, char *argv)
{
	if (exec->envvar == NULL)
	{
		exec->envvar = sh_copy_envvar(node->token->envvar);
		exec->envvar_curr = exec->envvar;
		exec->envvar_first = exec->envvar;
	}
	else
	{
		exec->envvar_curr->next = sh_copy_envvar(node->token->envvar);
		exec->envvar_curr = exec->envvar_curr->next;
	}
	while (exec->envvar_curr->next != NULL)
	{
		exec->envvar_curr->str = argv;
		exec->envvar_curr = exec->envvar_curr->next;
	}
	exec->envvar_curr->str = argv;
}

void		sh_exec_struct_write_redir_envvar
	(t_node *node, t_redirect *exec, char *argv)
{
	if (exec->envvar == NULL)
	{
		exec->envvar = sh_copy_envvar(node->token->envvar);
		exec->envvar_curr = exec->envvar;
		exec->envvar_first = exec->envvar;
	}
	else
	{
		exec->envvar_curr->next = sh_copy_envvar(node->token->envvar);
		exec->envvar_curr = exec->envvar_curr->next;
	}
	while (exec->envvar_curr->next != NULL)
	{
		exec->envvar_curr->str = argv;
		exec->envvar_curr = exec->envvar_curr->next;
	}
	exec->envvar_curr->str = argv;
}

t_envvar	*sh_create_new_envvar(void)
{
	t_envvar	*new;

	new = malloc(sizeof(t_envvar));
	new->start = 0;
	new->end = 0;
	new->type = -2;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

t_envvar	*sh_copy_envvar(t_envvar *from)
{
	t_envvar *temp;
	t_envvar *first;
	t_envvar *curr;
	t_envvar *new;

	temp = from;
	first = sh_create_new_envvar();
	first->start = temp->start;
	first->end = temp->end;
	first->type = temp->type;
	first->str = temp->str;
	temp = temp->next;
	curr = first;
	while (temp != NULL)
	{
		new = sh_create_new_envvar();
		new->start = temp->start;
		new->end = temp->end;
		new->type = temp->type;
		new->str = temp->str;
		curr->next = new;
		temp = temp->next;
		curr = curr->next;
	}
	return (first);
}
