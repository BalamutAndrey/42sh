/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:22:44 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 23:25:52 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** in               : In                       !! Apply rule 6 !!
*/

t_node	*sh_in(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_in_in(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** in               : In                       !! Apply rule 6 !!
*/

t_node	*sh_in_in(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
