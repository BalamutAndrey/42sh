/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_create_go.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:15:09 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 17:28:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
	}
	else if ((main->tree_curr->node_type == AND_IF) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 2);
	}
	else if ((main->tree_curr->node_type == OR_IF) &&
		(main->tree_curr->right != NULL))
	{
		main->tree_curr = temp->right;
		sh_exec_struct_go(main, 3);
	}
	else
	{
		sh_exec_struct_write(main, extsep);
	}
	main->tree_curr = temp;
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
		sh_exec_struct_go_left(main);
	}
	if ((sep == true) && (temp->left != NULL))
	{
		main->tree_curr = temp->left;
		sh_exec_struct_go(main, 0);
	}
}

void	sh_exec_struct_go_left(t_main *main)
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
		main->exec_curr->andif = true;
		sh_exec_struct_go(main, 2);
	}
	else if (main->tree_curr->node_type == OR_IF)
	{
		main->tree_curr = main->tree_curr->left;
		main->exec_curr->orif = true;
		sh_exec_struct_go(main, 3);
	}
}
