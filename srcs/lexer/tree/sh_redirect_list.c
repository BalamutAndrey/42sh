/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:29:43 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 17:26:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** redirect_list    :               io_redirect
**                  | redirect_list io_redirect
*/

t_node	*sh_redirectlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_redirectlist_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_redirectlist_redirectlist_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** redirect_list    :               io_redirect
*/

t_node	*sh_redirectlist_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** redirect_list    : redirect_list io_redirect
*/

t_node	*sh_redirectlist_redirectlist_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

bool	sh_is_a_redirect(t_token *token)
{
	if (token == NULL)
		return (false);
	if ((token->type == LESS) || (token->type == GREAT) ||
	(token->type == LESSAND) || (token->type == GREATAND) ||
	(token->type == DLESS) || (token->type == DGREAT) ||
	(token->type == IO_NUMBER))
	{
		return (true);
	}
	return (false);
}
