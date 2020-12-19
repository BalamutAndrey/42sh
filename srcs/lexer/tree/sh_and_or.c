/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:35:36 by eboris            #+#    #+#             */
/*   Updated: 2020/12/19 11:08:11 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** and_or           :                         pipeline
**                  | and_or AND_IF linebreak pipeline
**                  | and_or OR_IF  linebreak pipeline
*/

t_node	*sh_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_andor_andor_andif_linebreak_pipeline(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_andor_andor_orif_linebreak_pipeline(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_andor_pipeline(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** and_or           :                         pipeline
*/

t_node	*sh_andor_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_pipeline(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** and_or           : and_or AND_IF linebreak pipeline
*/

t_node	*sh_andor_andor_andif_linebreak_pipeline(t_main *main)
{
	t_node	*right;
	t_node	*left;
	t_node	*andif;
	t_token *token;

	token = main->token_curr;
	left = NULL;
	right = sh_pipeline(main);
	if ((right != NULL) && (main->token_curr != NULL) &&
		(main->token_curr->type == AND_IF))
	{
		andif = sh_lexer_create_node(main, main->token_curr, AND_IF);
		if (main->token_curr->next == NULL)
		{
			sh_lexer_del_all_node(&right);
			sh_lexer_del_all_node(&andif);
			return (sh_lexer_tree_error(main));
			// return (NULL);
		}
		main->token_curr = main->token_curr->next;
		left = sh_andor(main);
		if (left == NULL)
		{
			sh_lexer_del_all_node(&andif);
			sh_lexer_del_all_node(&right);
			return (sh_lexer_tree_error(main));
			// return (NULL);
		}
		sh_lexer_add_node(andif, left, right);
		return (andif);
	}
	main->token_curr = token;
	sh_lexer_del_all_node(&right);
	sh_lexer_del_all_node(&left);
	return (NULL);
}

/*
** and_or           : and_or OR_IF  linebreak pipeline
*/

t_node	*sh_andor_andor_orif_linebreak_pipeline(t_main *main)
{
	t_node	*right;
	t_node	*left;
	t_node	*orif;
	t_token *token;

	token = main->token_curr;
	right = sh_pipeline(main);
	left = NULL;
	if ((right != NULL) && (main->token_curr != NULL) &&
		(main->token_curr->type == OR_IF))
	{
		orif = sh_lexer_create_node(main, main->token_curr, OR_IF);
		if (main->token_curr->next == NULL)
		{
			sh_lexer_del_all_node(&right);
			sh_lexer_del_all_node(&orif);
			return (sh_lexer_tree_error(main));
			// return (NULL);
		}
		main->token_curr = main->token_curr->next;
		left = sh_andor(main);
		if (left == NULL)
		{
			sh_lexer_del_all_node(&orif);
			sh_lexer_del_all_node(&right);
			return (sh_lexer_tree_error(main));
			// return (NULL);
		}
		sh_lexer_add_node(orif, left, right);
		return (orif);
	}
	main->token_curr = token;
	sh_lexer_del_all_node(&right);
	sh_lexer_del_all_node(&left);
	return (NULL);
}
