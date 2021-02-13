/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:14:11 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:26:42 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_alias_recurs_change(t_main *main)
{
	t_alias		*al;

	al = main->alias;
	while (al)
	{
		if (al->recurs == 1)
			al->recurs = 2;
		al = al->next;
	}
}

void	sh_alias_space_next_token_check(t_main *main, t_token *tok)
{
	if (tok->next && tok->next->type == WORD &&
		(ft_strlen(tok->content) > 0) &&
		tok->content[ft_strlen(tok->content) - 1] == ' ')
	{
		if (sh_lexer_alias_selection(main, tok->next) == 1)
			sh_alias_space_next_token_check(main, tok->next);
	}
}

t_token	*sh_lexer_alias_check_tok_ch(t_token *tok)
{
	if ((sh_lexer_alias_is_redir(tok) == 1) && tok->next &&
			tok->next->type == WORD)
		return (tok->next->next);
	else
		return (tok->next);
}

int		sh_lexer_alias_check_tok_type(t_token *tok)
{
	if (tok->type == AND_IF || tok->type == AND_OR ||
		tok->type == SEPARATOR || tok->type == PIPELINE)
	{
		return (1);
	}
	return (0);
}

int		sh_lexer_alias_check(t_main *main, t_token *tok)
{
	int			flag;

	flag = 0;
	while (tok)
	{
		if (tok->type == WORD)
		{
			if (sh_lexer_alias_selection(main, tok) == 1 && flag == 0)
				flag = 1;
			while (tok)
			{
				if (flag == 1)
					sh_alias_space_next_token_check(main, tok);
				if (sh_lexer_alias_check_tok_type(tok) == 1)
					break ;
				tok = tok->next;
			}
		}
		else
			tok = sh_lexer_alias_check_tok_ch(tok);
	}
	sh_alias_recurs_change(main);
	if (flag == 1)
		sh_lexer_alias_change(main);
	return (flag);
}
