/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_prefix_assigment_word.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:30:35 by eboris            #+#    #+#             */
/*   Updated: 2020/12/09 16:33:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_prefix       :            ASSIGNMENT_WORD
*/

t_node	*sh_cmdprefix_assignment_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) ||
		(main->token_curr->type != ASSIGNMENT_WORD))
		return (NULL);
	temp = sh_lexer_create_node(main, main->token_curr, ASSIGNMENT_WORD);
	main->token_curr = main->token_curr->next;
	return (temp);
}

/*
** cmd_prefix       : cmd_prefix ASSIGNMENT_WORD
*/

t_node	*sh_cmdprefix_cmdprefix_assignment_word(t_main *main)
{
	t_node	*first;
	t_node	*curr;
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) ||
		(main->token_curr->type != ASSIGNMENT_WORD))
	{
		return (NULL);
	}
	if ((first = sh_cmdprefix_assignment_word(main)) != NULL)
	{
		curr = first;
		while (curr->right != NULL)
			curr = curr->right;
	}
	else
	{
		return (sh_lexer_tree_error(main));
	}
	return (sh_cmdprefix_assignment_word_while(main, first, curr, temp));
}

t_node	*sh_cmdprefix_assignment_word_while
	(t_main *main, t_node *first, t_node *curr, t_node *temp)
{
	while (main->token_curr != NULL && 
		(((sh_is_a_redirect(main->token_curr) == true)) ||
		(main->token_curr->type == ASSIGNMENT_WORD)))
	{
		if (((temp = sh_ioredirect(main)) != NULL) ||
			((temp = sh_cmdprefix_assignment_word(main)) != NULL))
		{
			sh_lexer_add_node(curr, NULL, temp);
			curr = temp;
			while (curr->right != NULL)
				curr = curr->right;
		}
		else
		{
			return (sh_lexer_tree_error(main));
		}
	}
	return (first);
}
