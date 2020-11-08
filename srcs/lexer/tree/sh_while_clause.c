/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_while_clause.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:25:07 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 13:26:58 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** while_clause     : While compound_list do_group
*/

t_node	*sh_whileclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_whileclause_while_compoundlist_dogroup(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** while_clause     : While compound_list do_group
*/

t_node	*sh_whileclause_while_compoundlist_dogroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
