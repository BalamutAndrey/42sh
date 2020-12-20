/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:59:55 by eboris            #+#    #+#             */
/*   Updated: 2020/12/20 16:13:33 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_prefix       :            io_redirect
**                  | cmd_prefix io_redirect
**                  |            ASSIGNMENT_WORD
**                  | cmd_prefix ASSIGNMENT_WORD
*/

t_node	*sh_cmdprefix(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdprefix_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_cmdprefix_cmdprefix_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_cmdprefix_cmdprefix_assignment_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_prefix       :            io_redirect
*/

t_node	*sh_cmdprefix_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type == WORD) ||
	(sh_is_a_redirect(main->token_curr) == false))
		return (NULL);
	if ((temp = sh_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_prefix       : cmd_prefix io_redirect
*/

t_node	*sh_cmdprefix_cmdprefix_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
