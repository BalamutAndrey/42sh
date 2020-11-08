/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:55:23 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 15:11:18 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void		sh_exec_struct_redirect(t_main *main)
{
	t_redirect	*first;
	t_redirect	*curr;
	t_redirect	*temp;
	t_node		*node;

	first = NULL;
	curr = NULL;
	node = main->tree_curr;
	while (node != NULL)
	{
		if (sh_is_a_redirect(node->token) == true)
		{
			temp = sh_exec_struct_redirect_new(main);
			node = sh_exec_struct_redirect_write(node, temp);
			if (first == NULL)
				sh_exec_struct_redirect_struct(&first, &temp, &curr, &first);
			else
			{
				curr->next = temp;
				curr = curr->next;
			}
		}
		node = node->right;
	}
	main->exec_curr->redir = first;
}

void		sh_exec_struct_redirect_struct
	(t_redirect **f1, t_redirect **t1, t_redirect **f2, t_redirect **t2)
{
	*f1 = *t1;
	*f2 = *t2;
}

t_redirect	*sh_exec_struct_redirect_new(t_main *main)
{
	t_redirect	*new;

	new = sh_memalloc(sizeof(t_redirect), main);
	new->io_num = -1;
	new->type = NONE;
	new->filename = NULL;
	new->next = NULL;
	new->envvar = NULL;
	new->envvar_first = NULL;
	new->envvar_curr = NULL;
	new->error = 0;
	return (new);
}

t_node		*sh_exec_struct_redirect_write(t_node *node, t_redirect *redirect)
{
	if (node->node_type == IO_NUMBER)
	{
		redirect->io_num = ft_atoi(node->token->content);
		node = node->right;
	}
	redirect->type = node->node_type;
	if (redirect->io_num == -1)
	{
		if ((node->node_type == LESS) || (node->node_type == DLESS) ||
		(node->node_type == LESSAND))
		{
			redirect->io_num = STDIN_FILENO;
		}
		else if ((node->node_type == GREAT) || (node->node_type == DGREAT) ||
		(node->node_type == GREATAND))
		{
			redirect->io_num = STDOUT_FILENO;
		}
	}
	node = node->right;
	redirect->filename = ft_strdup(node->token->content);
	if (node->token->envvar != NULL)
		sh_exec_struct_write_redir_envvar(node, redirect, redirect->filename);
	return (node);
}
