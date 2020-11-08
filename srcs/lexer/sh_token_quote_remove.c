/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_quote_remove.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:46:32 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 16:03:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_dslashes_remove(int i, int end, t_token *token, t_main *main)
{
	while (i < end)
	{
		if (token->content[i] == '\\' && token->content[i + 1] == '\\')
		{
			sh_remove_char(i, token, main);
			end--;
		}
		i++;
	}
	return (end);
}

int		sh_dquotes_remove(t_token *token, int i, t_main *main)
{
	int		tmp;

	tmp = i;
	sh_remove_char(i, token, main);
	while (token->content[i] != '\"' || sh_is_protected(token->content, i) == 1)
	{
		if (token->content[i] == '\\' &&
			(token->content[i + 1] == '\"' || token->content[i + 1] == '$') &&
			sh_is_protected(token->content, i) == 0)
		{
			sh_remove_char(i, token, main);
			i++;
		}
		else if (token->content[i] == '$' &&
			sh_is_protected(token->content, i) == 0 &&
			ft_isalpha(token->content[i + 1]) == 1)
			i = sh_add_envvar(1, i, main, token);
		else
			i++;
	}
	sh_remove_char(i, token, main);
	i = sh_dslashes_remove(tmp, i, token, main);
	return (i);
}

int		sh_squotes_remove(t_token *token, int i, t_main *main)
{
	sh_remove_char(i, token, main);
	while (token->content[i] != '\'')
		i++;
	sh_remove_char(i, token, main);
	return (i);
}
