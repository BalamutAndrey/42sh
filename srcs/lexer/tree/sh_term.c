/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:50:21 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 21:53:57 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** term             : term separator and_or
**                  |                and_or
*/

t_node	*sh_term(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_term_term_separator_andor(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_term_andor(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** term             : term separator and_or
*/

t_node	*sh_term_term_separator_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** term             :                and_or
*/

t_node	*sh_term_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
