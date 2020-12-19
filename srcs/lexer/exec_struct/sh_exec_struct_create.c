/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:51:20 by eboris            #+#    #+#             */
/*   Updated: 2020/12/19 09:48:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_struct_create(t_main *main)
{
	t_exec	*first;

	first = sh_exec_struct_new(main);
	main->exec_first = first;
	main->exec_curr = first;
	main->tree_curr = main->tree_first;
	sh_exec_struct_go(main, 0);
	if (main->exec_first->next != NULL)
	{
		first = main->exec_first;
		main->exec_first = main->exec_first->next;
		main->exec_curr = main->exec_first;
		sh_remove_exec_exec(first);
	}
	else
	{
		sh_remove_exec(main);
		main->exec_first = NULL;
	}
}

bool	sh_exec_struct_go_check(t_main *main, t_node *temp, int8_t extsep)
{
	bool sep;

	sep = false;
	if ((main->tree_curr->node_type == SEPARATOR) &&
		(main->tree_curr->right != NULL) &&
		((main->tree_curr->right->node_type == PIPELINE) ||
		(main->tree_curr->right->node_type == AND_IF) ||
		(main->tree_curr->right->node_type == OR_IF)))
	{
		main->tree_curr = temp->right->right;
		sh_exec_struct_go(main, 0);
		main->tree_curr = temp->right;
		sep = true;
	}
	else if ((main->tree_curr->node_type == SEPARATOR) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 0);
		main->tree_curr = temp;
	}
	else
		sh_exec_struct_go_check_else(main, temp, extsep);
	return (sep);
}

void	sh_exec_struct_go_check_else(t_main *main, t_node *temp, int8_t extsep)
{
	if ((main->tree_curr->node_type == PIPELINE) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 1);
		main->tree_curr = temp;
	}
	else if ((main->tree_curr->node_type == AND_IF) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 2);
		main->tree_curr = temp;
	}
	else if ((main->tree_curr->node_type == OR_IF) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 3);
		main->tree_curr = temp;
	}
	else
	{
		sh_exec_struct_write(main, extsep);
		main->tree_curr = temp;
	}
}

void	sh_exec_struct_go(t_main *main, int8_t extsep)
{
	t_node	*temp;
	bool	sep;

	sep = false;
	temp = main->tree_curr;
	if (temp != NULL)
		sep = sh_exec_struct_go_check(main, temp, extsep);
	if (main->tree_curr->left != NULL)
	{
		if (main->tree_curr->node_type == SEPARATOR)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, 0);
		}
		else if (main->tree_curr->node_type == PIPELINE)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, 1);
		}
		else if (main->tree_curr->node_type == AND_IF)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, 2);
		}
		else if (main->tree_curr->node_type == OR_IF)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, 3);
		}
	}
	if ((sep == true) && (temp->left != NULL))
	{
		main->tree_curr = temp->left;
		sh_exec_struct_go(main, 0);
	}
}

void	sh_exec_struct_write(t_main *main, int8_t extsep)
{
	t_node	*node;
	t_exec	*new;

	node = main->tree_curr;
	new = sh_exec_struct_new(main);
	main->exec_curr->next = new;
	main->exec_curr = main->exec_curr->next;
	sh_exec_struct_write_argv(main, new);
	sh_exec_struct_write_assigmentword(main);
	sh_exec_struct_redirect(main);
	new->pipe = false;
	new->andif = false;
	new->orif = false;
	if (extsep == 1)
		new->pipe = true;
	else if (extsep == 2)
		new->andif = true;
	else if (extsep == 3)
		new->orif = true;
	main->tree_curr = node;
}
