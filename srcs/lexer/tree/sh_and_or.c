/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:35:36 by eboris            #+#    #+#             */
/*   Updated: 2020/12/10 17:41:39 by eboris           ###   ########.fr       */
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
	right = sh_pipeline(main);
	if ((right != NULL) && (main->token_curr != NULL) &&
		(main->token_curr->type == AND_IF))
	{
		andif = sh_lexer_create_node(main, main->token_curr, AND_IF);
		if (main->token_curr->next == NULL)
		{
//			sh_lexer_tree_error(main);
			return (NULL);
		}
		main->token_curr = main->token_curr->next;
		left = sh_andor(main);
		if (left == NULL)
			return (NULL);
//			return (sh_lexer_tree_error(main));
		sh_lexer_add_node(andif, left, right);
		return (andif);
	}
	main->token_curr = token;
	return (NULL);
}

/*
** and_or           : and_or OR_IF  linebreak pipeline
*/

t_node	*sh_andor_andor_orif_linebreak_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
