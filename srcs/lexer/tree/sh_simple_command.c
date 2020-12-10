/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_simple_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:02:26 by eboris            #+#    #+#             */
/*   Updated: 2020/12/10 16:38:58 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** simple_command   : cmd_prefix cmd_word cmd_suffix
**                  | cmd_prefix cmd_word
**                  | cmd_prefix
**                  | cmd_name cmd_suffix
**                  | cmd_name
**
** !!! FILE: sh_simple_command_command.c !!!
*/

t_node	*sh_simplecommand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_simplecommand_cmdprefix_cmdword_cmdsuffix(main)) != NULL)
		return (temp);
	else if ((temp = sh_simplecommand_cmdprefix_cmdword(main)) != NULL)
		return (temp);
	else if ((temp = sh_simplecommand_cmdprefix(main)) != NULL)
		return (temp);
	else if ((temp = sh_simplecommand_cmdname_cmdsuffix(main)) != NULL)
		return (temp);
	else if ((temp = sh_simplecommand_cmdname(main)) != NULL)
	{
		if ((main->token_curr->next != NULL) &&
		(main->token_curr->next->type != SEPARATOR) &&
		(main->token_curr->next->type != PIPELINE) &&
		(main->token_curr->next->type != AND_IF) &&
		(main->token_curr->next->type != NEWLINE))
		{
			sh_lexer_del_node(&temp);
			return (NULL);
		}
		main->token_curr = main->token_curr->next;
		return (temp);
	}
	return (NULL);
}
