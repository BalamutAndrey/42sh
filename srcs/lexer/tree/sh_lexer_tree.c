/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:03:07 by eboris            #+#    #+#             */
/*   Updated: 2020/11/06 18:33:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_lexer_tree_new(t_main *main)
{
	t_node	*node;
	t_node	*end;

	sh_lexer_copy_token(main);
	node = sh_lexer_create_node(main, NULL, SEPARATOR);
	main->tree_first = node;
	main->tree_curr = node;
	main->token_curr = main->token;
	end = sh_complete_command(main, node);
}

void	sh_lexer_copy_token(t_main *main)
{
	t_token_free	*first;
	t_token_free	*new;
	t_token_free	*curr;
	t_token			*temp;

	temp = main->token;
	first = NULL;
	if (temp != NULL)
	{
		first = sh_memalloc(sizeof(t_token_free), main);
		first->token = temp;
		first->next = NULL;
		curr = first;
		temp = temp->next;
	}
	while (temp)
	{
		new = sh_memalloc(sizeof(t_token_free), main);
		new->token = temp;
		new->next = NULL;
		curr->next = new;
		curr = curr->next;
		temp = temp->next;
	}
	main->token_first = first;
}
