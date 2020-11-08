/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:35:05 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:37:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** pattern          :             WORD         !! Apply rule 4 !!
**                  | pattern '|' WORD         !! Do not apply rule 4 !!
*/

t_node	*sh_pattern(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_pattern_word(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_pattern_pattern_pipe_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** pattern          :             WORD         !! Apply rule 4 !!
*/

t_node	*sh_pattern_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** pattern          : pattern '|' WORD         !! Do not apply rule 4 !!
*/

t_node	*sh_pattern_pattern_pipe_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
