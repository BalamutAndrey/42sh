/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_case_item_ns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:06:17 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:14:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** case_item_ns     :     pattern ')'               linebreak
**                  |     pattern ')' compound_list linebreak
**                  | '(' pattern ')'               linebreak
**                  | '(' pattern ')' compound_list linebreak
*/

t_node	*caseitemns(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = caseitemns_pattern_bracket_linebreak(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
		caseitemns_pattern_bracket_compoundlist_linebreak(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
		caseitemns_bracket_pattern_bracket_linebreak(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
		caseitemns_bracket_pattern_bracket_compoundlist_linebreak(main)) !=
		NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** case_item_ns     :     pattern ')'               linebreak
*/

t_node	*caseitemns_pattern_bracket_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item_ns     :     pattern ')' compound_list linebreak
*/

t_node	*caseitemns_pattern_bracket_compoundlist_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item_ns     : '(' pattern ')'               linebreak
*/

t_node	*caseitemns_bracket_pattern_bracket_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_item_ns     : '(' pattern ')' compound_list linebreak
*/

t_node	*caseitemns_bracket_pattern_bracket_compoundlist_linebreak(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
