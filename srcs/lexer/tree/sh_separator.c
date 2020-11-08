/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:07:48 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 18:09:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** separator        : separator_op linebreak
**                  | newline_list
*/

t_node	*sh_separator(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_separator_separatorop_linebreak(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_separator_newlinelist(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** separator        : separator_op linebreak
*/

t_node	*sh_separator_separatorop_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** separator        : newline_list
*/

t_node	*sh_separator_newlinelist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
