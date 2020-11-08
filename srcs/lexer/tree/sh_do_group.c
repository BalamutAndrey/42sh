/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_do_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:52:26 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 14:53:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** do_group         : Do compound_list Done           !! Apply rule 6 !!
*/

t_node	*sh_dogroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_dogroup_do_compoundlist_done(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** do_group         : Do compound_list Done           !! Apply rule 6 !!
*/

t_node	*sh_dogroup_do_compoundlist_done(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
