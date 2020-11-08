/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote_remove_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:42:18 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 15:27:34 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_is_protected(char *str, int i)
{
	int		j;
	int		ret;

	j = 0;
	while (i > 0 && str[i - 1] == '\\')
	{
		i--;
		j++;
	}
	ret = j % 2 == 0 ? 0 : 1;
	return (ret);
}

void	sh_remove_char(int i, t_token *token, t_main *main)
{
	char	*ret;
	int		len;
	int		j;

	len = ft_strlen(token->content) - 1;
	j = 0;
	ret = sh_strnew(len, main);
	while (j < len)
	{
		if (j < i)
		{
			ret[j] = token->content[j];
			j++;
		}
		else
		{
			ret[j] = token->content[i + 1];
			j++;
			i++;
		}
	}
	ft_strdel(&token->content);
	token->content = ret;
	ret = NULL;
}
