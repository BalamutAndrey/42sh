/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_separator_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:01:13 by eboris            #+#    #+#             */
/*   Updated: 2020/09/21 17:53:12 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** separator_op     : '&'
**                  | ';'
*/

t_node	*sh_separatorop(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_separatorop_ampersand(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_separatorop_semicolon(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** separator_op     : '&'
*/

t_node	*sh_separatorop_ampersand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** separator_op     : ';'
*/

t_node	*sh_separatorop_semicolon(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr != NULL) && (main->token_curr->type == SEPARATOR) &&
	(main->token_curr->content[0] == ';'))
	{
		temp = sh_lexer_create_node(main, main->token_curr, SEPARATOR);
		return (temp);
	}
	return (NULL);
}
