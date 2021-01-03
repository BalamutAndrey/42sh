/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:14:11 by geliz             #+#    #+#             */
/*   Updated: 2021/01/03 19:01:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_lexer_alias_is_redir(t_token *tok)
{
	if (tok->type == LESS || tok->type == GREAT || tok->type == DLESS ||
		tok->type == DGREAT)
		return (1);
	else
		return (0);
}

char	*sh_lexer_alias_change(t_main *main, t_alias *al, t_token *tok)
{
	char	*ret;
	t_token	*main_tok;

	main_tok = main->token;
	ret = NULL;
	while (main_tok)
	{
		if (main_tok == tok)
			ret = sh_strjoin_arg(main, "%f %s %s", ret, " ", al->command);
		else
			ret = sh_strjoin_arg(main, "%f %s %s", ret, " ", main_tok->content);
		main_tok = main_tok->next;
	}
//	ft_strdel(&main->ks);
	return (ret);
	//зачистить всё, токены и енввары и прочая 
}

int		sh_lexer_alias_selection(t_main *main, t_token *tok)
{
	t_alias		*al;
	int			ret;

	al = main->alias;
	ret = 0;
	while (al)
	{
		if (ft_strcmp(al->name, tok->content) == 0)
		{
			main->ks_res = sh_lexer_alias_change(main, al, tok);
//			if (al->command[ft_strlen(al->command) - 1] == ' ' && tok->next &&
//				tok->next->type == WORD)
//				sh_lexer_alias_selection(main, tok->next);
			ret = 1;
//			sh_lexer_alias_selection(main, tok);
		}
		al = al->next;
	}
	return (ret);
}

int		sh_lexer_alias_check(t_main *main)
{
	t_token		*tok;
	int			flag;

	flag = 0;
	tok = main->token;
	while (tok)
	{
		if (tok->type == WORD)
		{
			flag = sh_lexer_alias_selection(main, tok);
			while (tok)
			{
				if (tok->type == AND_IF || tok->type == AND_OR ||
					tok->type == SEPARATOR || tok->type == PIPELINE)
					break;
				tok = tok->next;
			}
		}
		else if ((sh_lexer_alias_is_redir(tok) == 1) && tok->next &&
			tok->next->type == WORD)
			tok = tok->next->next;
		else
			tok = tok->next;
	}
	return (flag);
}
