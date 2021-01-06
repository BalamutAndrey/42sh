/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_check_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:14:02 by geliz             #+#    #+#             */
/*   Updated: 2021/01/06 14:21:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_count_quotes(t_main *main, int cq[2])
{
	int		i;
	char	*str;

	i = 0;
	str = main->ks;
	while (str[i])
	{
		if (str[i] == '\"' && cq[0] == 0)
		{
			if (sh_is_protected(str, i) == 0)
				cq[1]++;
		}
		else if (str[i] == '\'' && cq[1] == 0)
		{
			if ((cq[0] % 2 == 0 && sh_is_protected(str, i) == 0) ||
				cq[0] % 2 != 0)
				cq[0]++;
		}
		i++;
	}
}

/*
** cq == count quotes ; cq[0] - single quotes ; cq[1] - double quotes
*/

void	sh_check_quotes(t_main *main)
{
	int		cq[2];

	cq[0] = 0;
	cq[1] = 0;
	sh_count_quotes(main, cq);
	if (cq[1] > cq[0] && cq[1] % 2 != 0)
		main->prompt = sh_strdup("dquote", main);
	else if (cq[0] > cq[1] && cq[0] % 2 != 0)
		main->prompt = sh_strdup("quote", main);
	else
		ft_strdel(&main->prompt);
}
