/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_compound_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:24:37 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 21:31:12 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** compound_list    :              term
**                  | newline_list term
**                  |              term separator
**                  | newline_list term separator
*/

t_node	*sh_compoundlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_compoundlist_term(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundlist_newlinelist_term(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundlist_term_separator(main)) != NULL)
		return (temp);
	else if ((temp = sh_compoundlist_newlinelist_term_separator(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** compound_list    :              term
*/

t_node	*sh_compoundlist_term(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_list    : newline_list term
*/

t_node	*sh_compoundlist_newlinelist_term(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_list    :              term separator
*/

t_node	*sh_compoundlist_term_separator(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** compound_list    : newline_list term separator
*/

t_node	*sh_compoundlist_newlinelist_term_separator(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
