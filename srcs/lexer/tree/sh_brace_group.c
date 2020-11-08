/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_brace_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:49:09 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 14:50:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** brace_group      : Lbrace compound_list Rbrace
*/

t_node	*sh_bracegroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_bracegroup_lbrace_compoundlist_rbrace(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** brace_group      : Lbrace compound_list Rbrace
*/

t_node	*sh_bracegroup_lbrace_compoundlist_rbrace(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
