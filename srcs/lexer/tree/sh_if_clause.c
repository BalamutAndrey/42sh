/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_if_clause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:40:32 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:44:14 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** if_clause        : If compound_list Then compound_list else_part Fi
**                  | If compound_list Then compound_list           Fi
*/

t_node	*sh_ifclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp =
	sh_ifclause_if_compoundlist_then_compoundlist_elsepart_fi(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
	sh_ifclause_if_compoundlist_then_compoundlist_fi(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** if_clause        : If compound_list Then compound_list else_part Fi
*/

t_node	*sh_ifclause_if_compoundlist_then_compoundlist_elsepart_fi(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** if_clause        : If compound_list Then compound_list           Fi
*/

t_node	*sh_ifclause_if_compoundlist_then_compoundlist_fi(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
