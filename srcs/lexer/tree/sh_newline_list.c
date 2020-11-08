/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_newline_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:42:23 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 17:44:15 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** newline_list     :              NEWLINE
**                  | newline_list NEWLINE
*/

t_node	*sh_newlinelist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_newlinelist_newline(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_newlinelist_newlinelist_newline(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** newline_list     :              NEWLINE
*/

t_node	*sh_newlinelist_newline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** newline_list     : newline_list NEWLINE
*/

t_node	*sh_newlinelist_newlinelist_newline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
