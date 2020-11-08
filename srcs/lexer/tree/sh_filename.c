/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:19:12 by eboris            #+#    #+#             */
/*   Updated: 2020/09/25 17:44:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** filename         : WORD                      !! Apply rule 2 !!
*/

t_node	*sh_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_filename_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** filename         : WORD                      !! Apply rule 2 !!
*/

t_node	*sh_filename_word(t_main *main)
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
