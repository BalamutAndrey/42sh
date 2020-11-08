/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_until_clause.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:32:52 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 13:34:32 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** until_clause     : Until compound_list do_group
*/

t_node	*sh_untilclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_untilclause_until_compoundlist_dogroup(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** until_clause     : Until compound_list do_group
*/

t_node	*sh_untilclause_until_compoundlist_dogroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
