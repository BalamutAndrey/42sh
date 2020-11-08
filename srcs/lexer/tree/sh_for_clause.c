/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_for_clause.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:30:57 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 22:40:10 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** for_clause       : For name linebreak                            do_group
**                  | For name linebreak in          sequential_sep do_group
**                  | For name linebreak in wordlist sequential_sep do_group
*/

t_node	*sh_forclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp =
		sh_forclause_for_name_linebreak_dogroup(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
		sh_forclause_for_name_linebreak_in_sequentialsep_dogroup(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp =
		sh_forclause_for_name_linebreak_in_wordlist_sequentialsep_dogroup(main))
		!= NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** for_clause       : For name linebreak                            do_group
*/

t_node	*sh_forclause_for_name_linebreak_dogroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** for_clause       : For name linebreak in          sequential_sep do_group
*/

t_node	*sh_forclause_for_name_linebreak_in_sequentialsep_dogroup(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** for_clause       : For name linebreak in wordlist sequential_sep do_group
*/

t_node	*sh_forclause_for_name_linebreak_in_wordlist_sequentialsep_dogroup
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
