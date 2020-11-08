/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:31:07 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 14:45:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_heredoc(t_main *main)
{
	t_heredoc	*temp;

	if (main->heredoc != NULL)
	{
		temp = main->heredoc;
		while (temp != NULL)
		{
			main->heredoc = temp->next;
			if (temp->delim != NULL)
				ft_strdel(&temp->delim);
			if (temp->content != NULL)
				ft_strdel(&temp->content);
			free(temp);
			temp = main->heredoc;
		}
		main->heredoc = NULL;
	}
}
