/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:14:11 by geliz             #+#    #+#             */
/*   Updated: 2021/01/05 20:57:30 by geliz            ###   ########.fr       */
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

void	sh_lexer_alias_change(t_main *main)
{
	char	*ret;
	t_token	*main_tok;

	main_tok = main->token;
	ret = NULL;
	while (main_tok)
	{
		if (main_tok->type == NEWLINE)
			ret = sh_strjoin_arg(main, "%f %s", ret, "\n");
		else
			ret = sh_strjoin_arg(main, "%f %s %s", ret, " ", main_tok->content);
	//	if (main_tok->type != NEWLINE)
	//		ret = sh_strjoin_arg(main, "%f %s %s", ret, " ", main_tok->content);
		main_tok = main_tok->next;
	}
	main->ks_res = ret;
//	ft_printf("here = %s\n", main->ks_res);
	//зачистить всё, токены и енввары и прочая -- 0501 ????
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
//			ft_printf("her;");
			ft_strdel(&tok->content);
			tok->content = sh_strdup(al->command, main);
			
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
//		ft_printf("tok = %i%s\n", tok->type, tok->content);
		if (tok->type == WORD)
		{
//			ft_printf("t_cont = %s\n", tok->content);
			if (sh_lexer_alias_selection(main, tok) == 1 && flag == 0)
				flag = 1;
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
	if (flag == 1)
		sh_lexer_alias_change(main);
	return (flag);
}
