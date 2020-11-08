/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_case_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:06:31 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:00:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** case_list        : case_list case_item
**                  |           case_item
*/

t_node	*sh_caselist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_caselist_caselist_caseitem(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_caselist_caseitem(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** case_list        : case_list case_item
*/

t_node	*sh_caselist_caselist_caseitem(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_list        :           case_item
*/

t_node	*sh_caselist_caseitem(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
