/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_find_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:21:26 by geliz             #+#    #+#             */
/*   Updated: 2020/12/20 18:06:57 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_find_closing_single_quotes(int i, char *str)
{
	i++;
	while (str[i] != '\0' && str[i] != '\'')
		i++;
//	if (str[i] != '\0')
//		i++;
	return (i);
}

int		sh_find_closing_double_quotes(int i, char *str)
{
	i++;
	while (str[i] != '\0' && str[i] != '"')
	{
		if (str[i] == '"' && sh_is_protected(str, i) == 0)
			return (i);
		i++;
	}
//	if (str[i] != '\0')
//		i++;
	return (i);
}
