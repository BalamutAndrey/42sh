/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:19:08 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 18:57:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** command          : simple_command
**                  | compound_command
**                  | compound_command redirect_list
**                  | function_definition
*/

t_node	*sh_command(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_command_simplecommand(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_command_compoundcommand(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_command_compoundcommand_redirectlist(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_command_functiondefinition(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** command          : simple_command
*/

t_node	*sh_command_simplecommand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_simplecommand(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** command          : compound_command
*/

t_node	*sh_command_compoundcommand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** command          : compound_command redirect_list
*/

t_node	*sh_command_compoundcommand_redirectlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** command          : function_definition
*/

t_node	*sh_command_functiondefinition(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
