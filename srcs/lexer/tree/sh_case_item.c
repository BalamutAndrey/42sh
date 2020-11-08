/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_case_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:16:54 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:27:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** case_item        :     pattern ')' linebreak     DSEMI linebreak
**                  |     pattern ')' compound_list DSEMI linebreak
**                  | '(' pattern ')' linebreak     DSEMI linebreak
**                  | '(' pattern ')' compound_list DSEMI linebreak
*/

t_node	*sh_caseitem(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp =
	sh_caseitem_pattern_bracket_linebreak_dsemi_linebreak(main)) != NULL)
		return (temp);
	else if ((temp =
	sh_caseitem_pattern_bracket_compoundlist_dsemi_linebreak(main)) != NULL)
		return (temp);
	else if ((temp =
	sh_caseitem_bracket_pattern_bracket_linebreak_dsemi_linebreak(main)) !=
	NULL)
		return (temp);
	else if ((temp =
	sh_caseitem_bracket_pattern_bracket_compoundlist_dsemi_linebreak(main)) !=
	NULL)
		return (temp);
	return (NULL);
}

/*
** case_item        :     pattern ')' linebreak     DSEMI linebreak
*/

t_node	*sh_caseitem_pattern_bracket_linebreak_dsemi_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item        :     pattern ')' compound_list DSEMI linebreak
*/

t_node	*sh_caseitem_pattern_bracket_compoundlist_dsemi_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item        : '(' pattern ')' linebreak     DSEMI linebreak
*/

t_node	*sh_caseitem_bracket_pattern_bracket_linebreak_dsemi_linebreak
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item        : '(' pattern ')' compound_list DSEMI linebreak
*/

t_node	*sh_caseitem_bracket_pattern_bracket_compoundlist_dsemi_linebreak
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
