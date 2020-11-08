/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:00:27 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 17:29:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_find_and_remove_quotes(t_main *main, t_token *token)
{
	int		i;

	i = 0;
	while (token->content[i])
	{
		if (token->content[i] == '\"' &&
		sh_is_protected(token->content, i) == 0)
			i = sh_dquotes_remove(token, i, main);
		else if (token->content[i] == '\'' &&
		sh_is_protected(token->content, i) == 0)
			i = sh_squotes_remove(token, i, main);
		else if (token->content[i] == '$' &&
		sh_is_protected(token->content, i) == 0
		&& ft_isalpha(token->content[i + 1]) == 1)
			i = sh_add_envvar(1, i, main, token);
		else if (token->content[i] == '\\')
		{
			sh_remove_char(i, token, main);
			i++;
		}
		else
			i++;
	}
}

void	sh_find_envvar(t_token *token, t_main *main)
{
	int		i;

	i = 0;
	while (token->content[i])
	{
		if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0
			&& ft_isalpha(token->content[i + 1]) == 1)
			i = sh_add_envvar(1, i, main, token);
		i++;
	}
}

void	sh_quote_remove(t_main *main, t_token *token)
{
	while (token)
	{
		if (token->type == DLESS && token->next && token->next->type == WORD)
		{
			sh_find_envvar(token->next, main);
			token = token->next->next;
		}
		else if (token->type == WORD)
		{
			if (token->content[0] == '~' && (token->content[1] == '\0' ||
				token->content[1] == '/'))
				sh_add_envvar(0, 0, main, token);
			else
				sh_find_and_remove_quotes(main, token);
		}
		if (token)
			token = token->next;
	}
}
