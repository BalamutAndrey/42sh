/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sequential_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:11:21 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 18:14:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** sequential_sep   : ';' linebreak
**                  | newline_list
*/

t_node	*sh_sequentialsep(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_sequentialsep_semicolon_linebreak(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_sequentialsep_newlinelist(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** sequential_sep   : ';' linebreak
*/

t_node	*sh_sequentialsep_semicolon_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** sequential_sep   : newline_list
*/

t_node	*sh_sequentialsep_newlinelist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
