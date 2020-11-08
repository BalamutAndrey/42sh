/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:34:08 by eboris            #+#    #+#             */
/*   Updated: 2020/11/06 16:46:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** io_redirect      :           io_file
**                  | IO_NUMBER io_file
**                  |           io_here
**                  | IO_NUMBER io_here
*/

t_node	*sh_ioredirect(t_main *main)
{
	t_node	*first;
	t_node	*curr;
	t_node	*temp;

	temp = NULL;
	if (sh_is_a_redirect(main->token_curr) == false)
		return (NULL);
	if (((first = sh_ioredirect_iofile(main)) != NULL) ||
	((first = sh_ioredirect_ionumber_iofile(main)) != NULL) ||
	((first = sh_ioredirect_iohere(main)) != NULL) ||
	((first = sh_ioredirect_ionumber_iohere(main)) != NULL))
	{
		curr = first;
		while (curr->right != NULL)
			curr = curr->right;
	}
	else
	{
		if (main->token != NULL)
			sh_lexer_tree_error(main);
		return (NULL);
	}
	return (sh_ioredirect_while(main, first, curr, temp));
}

t_node	*sh_ioredirect_while
	(t_main *main, t_node *first, t_node *curr, t_node *temp)
{
	while (sh_is_a_redirect(main->token_curr) == true)
	{
		if (((temp = sh_ioredirect_iofile(main)) != NULL) ||
		((temp = sh_ioredirect_ionumber_iofile(main)) != NULL) ||
		((temp = sh_ioredirect_iohere(main)) != NULL) ||
		((temp = sh_ioredirect_ionumber_iohere(main)) != NULL))
		{
			sh_lexer_add_node(curr, NULL, temp);
			curr = temp;
			while (curr->right != NULL)
				curr = curr->right;
		}
		else
		{
			sh_lexer_tree_error(main);
			return (NULL);
		}
	}
	return (first);
}
