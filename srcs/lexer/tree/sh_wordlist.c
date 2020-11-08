/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_wordlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:30:26 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 16:33:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** wordlist         : wordlist WORD
**                  |          WORD
*/

t_node	*sh_wordlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_wordlist_wordlist_word(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_wordlist_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** wordlist         : wordlist WORD
*/

t_node	*sh_wordlist_wordlist_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** wordlist         :          WORD
*/

t_node	*sh_wordlist_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
