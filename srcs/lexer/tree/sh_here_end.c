/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_here_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:25:48 by eboris            #+#    #+#             */
/*   Updated: 2020/10/02 16:32:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** here_end         : WORD                      !! Apply rule 3 !!
*/

t_node	*sh_hereend(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_hereend_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** here_end         : WORD                      !! Apply rule 3 !!
*/

t_node	*sh_hereend_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr != NULL) && (main->token_curr->type == WORD))
	{
		temp = sh_lexer_create_node(main, main->token_curr, WORD);
		return (temp);
	}
	return (NULL);
}
