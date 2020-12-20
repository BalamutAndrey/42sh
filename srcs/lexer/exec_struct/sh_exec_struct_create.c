/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:51:20 by eboris            #+#    #+#             */
/*   Updated: 2020/12/20 17:15:41 by eboris           ###   ########.fr       */
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
