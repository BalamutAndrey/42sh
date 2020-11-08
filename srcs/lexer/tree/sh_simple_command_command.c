/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_simple_command_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:03:57 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 18:40:14 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** !!! MAIN FILE: sh_simple_command.c !!!
**
** simple_command   : cmd_prefix cmd_word cmd_suffix
*/

t_node	*sh_simplecommand_cmdprefix_cmdword_cmdsuffix(t_main *main)
{
	t_node	*prf_cmd;
	t_node	*suff;
	t_node	*for_suff;
	t_token	*temp;

	temp = main->token_curr;
	if ((prf_cmd = sh_simplecommand_cmdprefix_cmdword(main)) == NULL)
	{
		if (main->token_curr != NULL)
			main->token_curr = temp;
		return (NULL);
	}
	if ((suff = sh_cmdsuffix(main)) == NULL)
	{
		sh_lexer_del_node(&suff);
		main->token_curr = temp;
		return (NULL);
	}
	for_suff = prf_cmd;
	while (for_suff->right != NULL)
		for_suff = for_suff->right;
	sh_lexer_add_node(for_suff, NULL, suff);
	return (prf_cmd);
}

/*
** simple_command   : cmd_prefix cmd_word
*/

t_node	*sh_simplecommand_cmdprefix_cmdword(t_main *main)
{
	t_node	*cmd;
	t_node	*prefix;
	t_node	*for_cmd;
	t_token	*before_prefix;

	before_prefix = main->token_curr;
	if ((prefix = sh_cmdprefix(main)) == NULL)
		return (NULL);
	if (main->token_curr == NULL)
	{
		sh_lexer_del_all_node(&prefix);
		return (NULL);
	}
	if ((cmd = sh_cmdname(main)) == NULL)
	{
		sh_lexer_del_all_node(&prefix);
		main->token_curr = before_prefix;
		return (NULL);
	}
	for_cmd = prefix;
	while (for_cmd->right != NULL)
		for_cmd = for_cmd->right;
	sh_lexer_add_node(for_cmd, NULL, cmd);
	main->token_curr = main->token_curr->next;
	return (prefix);
}

/*
** simple_command   : cmd_prefix
*/

t_node	*sh_simplecommand_cmdprefix(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdprefix(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** simple_command   : cmd_name cmd_suffix
*/

t_node	*sh_simplecommand_cmdname_cmdsuffix(t_main *main)
{
	t_node	*cmd;
	t_node	*suffix;
	t_token	*temp;

	temp = main->token_curr;
	if ((cmd = sh_cmdname(main)) == NULL)
		return (NULL);
	main->token_curr = main->token_curr->next;
	if ((suffix = sh_cmdsuffix(main)) == NULL)
	{
		sh_lexer_del_node(&cmd);
		if (main->token != NULL)
			main->token_curr = temp;
		return (NULL);
	}
	sh_lexer_add_node(cmd, NULL, suffix);
	return (cmd);
}

/*
** simple_command   : cmd_name
*/

t_node	*sh_simplecommand_cmdname(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdname(main)) == NULL)
		return (NULL);
	if ((main->token_curr->next == NULL) ||
		(main->token_curr->next->type == SEPARATOR) ||
		(main->token_curr->next->type == PIPELINE) ||
		(main->token_curr->next->type == NEWLINE))
	{
		return (temp);
	}
	else
	{
		sh_lexer_del_node(&temp);
		sh_lexer_tree_error(main);
		return (NULL);
	}
	return (NULL);
}
