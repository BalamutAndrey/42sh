/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_function_definition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:37:05 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 15:15:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** function_definition : fname '(' ')' linebreak function_body
*/

t_node	*sh_functiondefinition(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp =
	sh_functiondefinition_fname_bracket_bracket_linebreak_functionbody(main)) !=
	NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** function_definition : fname '(' ')' linebreak function_body
*/

t_node	*sh_functiondefinition_fname_bracket_bracket_linebreak_functionbody
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
