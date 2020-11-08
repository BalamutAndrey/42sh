/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:50:58 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:38:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_name         : WORD                   !! Apply rule 7a !!
*/

t_node	*sh_cmdname(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdname_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_name         : WORD                   !! Apply rule 7a !!
*/

t_node	*sh_cmdname_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type != WORD))
		return (NULL);
	temp = sh_lexer_create_node(main, main->token_curr, CMDNAME);
	return (temp);
}
