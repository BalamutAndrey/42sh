/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_heredoc_quotes_rm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:59:11 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 15:13:52 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_heredoc_dslashes_remove(int i, int end, t_heredoc *here,
			t_main *main)
{
	while (i < end)
	{
		if (here->delim[i] == '\\' && here->delim[i + 1] == '\\')
			sh_heredoc_remove_char(i, here, main);
		i++;
		end--;
	}
	return (end);
}

int		sh_heredoc_dquotes_remove(t_heredoc *here, int i, t_main *main)
{
	int		tmp;

	tmp = i;
	sh_heredoc_remove_char(i, here, main);
	while (here->delim[i] != '\"' || sh_is_protected(here->delim, i) == 1)
	{
		if (here->delim[i] == '\\' && here->delim[i + 1] == '\"' &&
			sh_is_protected(here->delim, i) == 0)
		{
			sh_heredoc_remove_char(i, here, main);
			i++;
		}
		else
			i++;
	}
	sh_heredoc_remove_char(i, here, main);
	i = sh_heredoc_dslashes_remove(tmp, i, here, main);
	return (i + 1);
}

int		sh_heredoc_squotes_remove(t_heredoc *here, int i, t_main *main)
{
	sh_heredoc_remove_char(i, here, main);
	while (here->delim[i] != '\'')
		i++;
	sh_heredoc_remove_char(i, here, main);
	return (i);
}
