/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_function_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:10:03 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 14:12:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** function_body    : compound_command                !! Apply rule 9 !!
**                  | compound_command redirect_list  !! Apply rule 9 !!
*/

t_node	*sh_functionbody(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_functionbody_compoundcommand(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_functionbody_compoundcommand_redirectlist(main)) !=
		NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** function_body    : compound_command                !! Apply rule 9 !!
*/

t_node	*sh_functionbody_compoundcommand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** function_body    : compound_command redirect_list  !! Apply rule 9 !!
*/

t_node	*sh_functionbody_compoundcommand_redirectlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
