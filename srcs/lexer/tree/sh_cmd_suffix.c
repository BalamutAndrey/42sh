/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_suffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:29:27 by eboris            #+#    #+#             */
/*   Updated: 2020/12/10 16:53:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_suffix       :            io_redirect
**                  | cmd_suffix io_redirect
**                  |            WORD
**                  | cmd_suffix WORD
*/

t_node	*sh_cmdsuffix(t_main *main)
{
	t_node	*first;
	t_node	*curr;
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type == SEPARATOR) || (main->token_curr->type == AND_IF) ||
	(main->token_curr->type == PIPELINE) || (main->token_curr->type == NEWLINE))
		return (NULL);
	if ((sh_is_a_redirect(main->token_curr) == false) &&
		(main->token_curr->type != WORD))
	{
		return (sh_lexer_tree_error(main));
	}
	if (((first = sh_ioredirect(main)) != NULL) ||
		((first = sh_cmdsuffix_word(main)) != NULL))
	{
		curr = first;
		while (curr->right != NULL)
			curr = curr->right;
	}
	else
	{
		return (sh_lexer_tree_error(main));
	}
	return (sh_cmdsuffix_while(main, first, curr, temp));
}

t_node	*sh_cmdsuffix_while
	(t_main *main, t_node *first, t_node *curr, t_node *temp)
{
	while (main->token_curr != NULL && main->token_curr->type != SEPARATOR && main->token_curr->type != AND_IF &&
	(main->token_curr->type != PIPELINE) && (main->token_curr->type != NEWLINE))
	{
		if ((sh_is_a_redirect(main->token_curr) == false) &&
			(main->token_curr->type != WORD))
		{
			return (sh_lexer_tree_error(main));
		}
		if (((temp = sh_ioredirect(main)) != NULL) ||
			((temp = sh_cmdsuffix_word(main)) != NULL))
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

t_node	*sh_cmdsuffix_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type != WORD))
		return (NULL);
	temp = sh_lexer_create_node(main, main->token_curr, CMDSUFFIX);
	main->token_curr = main->token_curr->next;
	return (temp);
}
