/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_linebreak.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:57:07 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 18:00:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** linebreak        : newline_list
**                  | !!! empty !!!
*/

t_node	*sh_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_linebreak_newlinelist(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_linebreak_empty(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** linebreak        : newline_list
*/

t_node	*sh_linebreak_newlinelist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** linebreak        : !!! empty !!!
*/

t_node	*sh_linebreak_empty(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
