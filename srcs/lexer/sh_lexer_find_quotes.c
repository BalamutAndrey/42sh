/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_find_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:21:26 by geliz             #+#    #+#             */
/*   Updated: 2020/09/06 17:14:58 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_find_closing_single_quotes(int i, char *str)
{
	i++;
	while (str[i] != '\0' && str[i] != '\'')
		i++;
	return (i);
}

int		sh_find_closing_double_quotes(int i, char *str)
{
	i++;
	while (str[i] != '\0' && str[i] != '"')
	{
		i++;
		if (i - 1 >= 0 && str[i] == '"' && str[i - 1] == '\\')
			i++;
	}
	return (i);
}
