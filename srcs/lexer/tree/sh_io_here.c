/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:22:01 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 17:25:33 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** io_here          : DLESS     here_end
**                  | DLESSDASH here_end
*/

t_node	*sh_iohere(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_iohere_dless_hereend(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_iohere_dlessdash_hereend(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** io_here          : DLESS     here_end
*/

t_node	*sh_iohere_dless_hereend(t_main *main)
{
	t_node	*temp;
	t_node	*first;
	t_token	*token;

	temp = NULL;
	token = main->token_curr;
	if ((main->token_curr != NULL) && (main->token_curr->type == DLESS))
	{
		first = sh_lexer_create_node(main, main->token_curr, DLESS);
		main->token_curr = main->token_curr->next;
		if ((temp = sh_hereend(main)) != NULL)
		{
			sh_lexer_add_node(first, NULL, temp);
			main->token_curr = main->token_curr->next;
			return (first);
		}
		else
		{
			main->token_curr = token;
			sh_lexer_tree_error(main);
			return (NULL);
		}
	}
	return (NULL);
}

/*
** io_here          : DLESSDASH here_end
*/

t_node	*sh_iohere_dlessdash_hereend(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
