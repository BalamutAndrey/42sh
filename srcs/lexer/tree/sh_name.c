/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:56:56 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 22:58:52 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** name             : NAME                     !! Apply rule 5 !!
*/

t_node	*sh_name(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_name_name(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** name             : NAME                     !! Apply rule 5 !!
*/

t_node	*sh_name_name(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
