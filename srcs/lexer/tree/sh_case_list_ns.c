/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_case_list_ns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:00:13 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 17:03:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** case_list_ns     : case_list case_item_ns
**                  |           case_item_ns
*/

t_node	*sh_caselistns(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_caselistns_caselist_caseitemns(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_caselistns_caseitemns(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** case_list_ns     : case_list case_item_ns
*/

t_node	*sh_caselistns_caselist_caseitemns(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_list_ns     :           case_item_ns
*/

t_node	*sh_caselistns_caseitemns(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
