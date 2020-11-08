/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:42:42 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 14:43:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_token(t_main *main)
{
	t_token			*temp;
	t_token_free	*curr;

	curr = main->token_first;
	while (curr)
	{
		temp = curr->token;
		if (temp->content != NULL)
		{
			ft_strdel(&temp->content);
		}
		if (temp->envvar != NULL)
		{
			sh_remove_envvar(temp->envvar);
			temp->envvar = NULL;
		}
		free(temp);
		curr = curr->next;
	}
	main->token = NULL;
	main->token_curr = NULL;
	sh_remove_token_lists(main);
}

void	sh_remove_token_lists(t_main *main)
{
	t_token_free	*temp;

	temp = main->token_first;
	while (temp)
	{
		main->token_first = temp->next;
		free(temp);
		temp = main->token_first;
	}
	main->token_first = NULL;
}
