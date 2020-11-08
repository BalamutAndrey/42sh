/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_else_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:46:51 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:50:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** else_part        : Elif compound_list Then else_part
**                  | Else compound_list
*/

t_node	*sh_elsepart(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_elsepart_elif_compoundlist_then_elsepart(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_elsepart_elif_compoundlist(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** else_part        : Elif compound_list Then else_part
*/

t_node	*sh_elsepart_elif_compoundlist_then_elsepart(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** else_part        : Else compound_list
*/

t_node	*sh_elsepart_elif_compoundlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
