/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:55:08 by eboris            #+#    #+#             */
/*   Updated: 2020/09/20 17:39:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_word         : WORD                   !! Apply rule 7b !!
*/

t_node	*sh_cmdword(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdword_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_word         : WORD                   !! Apply rule 7b !!
*/

t_node	*sh_cmdword_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if (main->token_curr->type != WORD)
		return (NULL);
	temp = sh_lexer_create_node(main, main->token_curr, CMDNAME);
	main->token_curr = main->token_curr->next;
	return (temp);
}
