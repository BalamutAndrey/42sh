/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_compound_command_clause.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 19:15:35 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 19:22:00 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** !!! Main file is sh_compound_command.c !!!
**
** compound_command : brace_group
**                  | subshell
**                  | for_clause
**                  | case_clause
**                  | if_clause
**                  | while_clause
**                  | until_clause
*/

/*
** compound_command : for_clause
*/

t_node	*sh_compoundcommand_forclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_command : case_clause
*/

t_node	*sh_compoundcommand_caseclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_command : if_clause
*/

t_node	*sh_compoundcommand_ifclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_command : while_clause
*/

t_node	*sh_compoundcommand_whileclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_command : until_clause
*/

t_node	*sh_compoundcommand_untilclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
