/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_compound_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:13:59 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 19:27:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** compound_command : brace_group
**                  | subshell
**                  | for_clause
**                  | case_clause
**                  | if_clause
**                  | while_clause
**                  | until_clause
**
** !!! Clause-command in file sh_compound_command_clause.c !!!
*/

t_node	*sh_compoundcommand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_compoundcommand_bracegroup(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_subshell(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_forclause(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_caseclause(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_ifclause(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_whileclause(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundcommand_untilclause(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** compound_command : brace_group
*/

t_node	*sh_compoundcommand_bracegroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_command : subshell
*/

t_node	*sh_compoundcommand_subshell(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
