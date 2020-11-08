/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_add_heredoc_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:39:51 by geliz             #+#    #+#             */
/*   Updated: 2020/10/16 18:10:17 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_delete_heredoc_struct(t_main *main)
{
	t_heredoc	*here;
	t_heredoc	*nxt;

	here = main->heredoc;
	while (here)
	{
		ft_strdel(&here->delim);
		ft_strdel(&here->content);
		nxt = here->next;
		here->next = NULL;
		free(here);
		here = nxt;
	}
	main->heredoc = NULL;
}

void	sh_add_heredoc_content(t_main *main)
{
	t_heredoc	*here;
	t_token		*tok;

	here = main->heredoc;
	tok = main->token;
	while (tok)
	{
		if (tok->type == DLESS)
		{
			ft_strdel(&tok->next->content);
			tok->next->content = ft_strdup(here->content);
			here = here->next;
		}
		tok = tok->next;
	}
	sh_delete_heredoc_struct(main);
}
