/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:43:26 by geliz             #+#    #+#             */
/*   Updated: 2021/01/06 14:20:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_check_slash_is_quoted(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\"' && count % 2 == 0 && sh_is_protected(str, i) == 0)
		{
			while (str[i])
			{
				if (str[i] == '\"' && sh_is_protected(str, i))
					break ;
				i++;
			}
		}
		else if (str[i] == '\'' && count % 2 == 0 &&
			sh_is_protected(str, i) == 0)
			count++;
		else if (str[i] == '\'' && count % 2 != 0)
			count++;
		i++;
	}
	i = count % 2 == 0 ? 0 : 1;
	return (i);
}

void	sh_check_slash(t_main *main)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = main->ks;
	j = ft_strlen(str);
	while (j > 0 && str[j - 1] == '\\')
	{
		j--;
		i++;
	}
	if (i % 2 != 0 && sh_check_slash_is_quoted(str) == 0)
		main->prompt = sh_strdup("slash", main);
}
