/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:16:03 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 21:18:39 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** subshell         : '(' compound_list ')'
*/

t_node	*sh_subshell(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_subshell_bracket_compoundlist_bracket(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** subshell         : '(' compound_list ')'
*/

t_node	*sh_subshell_bracket_compoundlist_bracket(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
