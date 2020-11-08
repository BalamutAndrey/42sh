/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 14:45:33 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 14:46:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** fname            : NAME                            !! Apply rule 8 !!
*/

t_node	*sh_fname(t_main main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_fname_name(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** fname            : NAME                            !! Apply rule 8 !!
*/

t_node	*sh_fname_name(t_main main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
