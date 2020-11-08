/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:42:46 by geliz             #+#    #+#             */
/*   Updated: 2020/11/04 16:53:22 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_erase_heredoc_content_from_ks(t_main *main, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		main->ks[start + i] = '\0';
		i++;
	}
}

void	sh_get_heredoc_content(t_main *main)
{
	t_heredoc	*tmp;

	tmp = main->heredoc;
	while (tmp->here_end != -1)
	{
		if (tmp->next && tmp->next->here_start == -1)
			tmp->next->here_start = tmp->here_end;
		tmp = tmp->next;
	}
	if (ft_strstr(&main->ks[tmp->here_start], tmp->delim))
	{
		tmp->here_end = ft_strlen(main->ks);
		tmp->content = sh_strsub(main->ks, tmp->here_start + 1,
			ft_strlen(main->ks) - tmp->here_start - ft_strlen(tmp->delim),
				main);
	}
	else if (ft_strchr(&main->ks[tmp->here_start], 4))
	{
		tmp->here_end = ft_strlen(main->ks);
		tmp->content = sh_strsub(main->ks, tmp->here_start + 1,
			ft_strlen(main->ks) - tmp->here_start - 1, main);
	}
}

int		sh_is_heredoc_finished(t_main *main)
{
	t_heredoc	*tmp;

	tmp = main->heredoc;
	while (tmp)
	{
		if (tmp->here_end == -1)
		{
			if (main->prompt)
				ft_strdel(&main->prompt);
			main->prompt = sh_strdup("Heredoc", main);
			return (0);
		}
		tmp = tmp->next;
	}
	if (main->prompt)
	{
		ft_strdel(&main->prompt);
		main->prompt = NULL;
	}
	return (1);
}

void	sh_erase_heredoc_from_ks(t_main *main)
{
	t_heredoc	*tmp;

	tmp = main->heredoc;
	while (tmp)
	{
		sh_erase_heredoc_content_from_ks(main, tmp->here_start,
			ft_strlen(tmp->content));
		tmp = tmp->next;
	}
	ft_strdel(&main->hist_end->prev->com);
	main->hist_end->prev->com = sh_strdup(main->ks, main);
}

int		sh_check_heredoc(t_main *main)
{
	int		err;

	if (!main->heredoc)
	{
		err = sh_create_heredoc_structs(main);
		if (err == -2)
			return (err);
	}
	if (main->heredoc)
	{
		sh_heredoc_delim_correction(main);
		if (sh_is_heredoc_finished(main) == 0)
			sh_get_heredoc_content(main);
		if (sh_is_heredoc_finished(main) == 1)
			sh_erase_heredoc_from_ks(main);
	}
	return (0);
}
