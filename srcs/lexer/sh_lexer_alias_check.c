/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:14:11 by geliz             #+#    #+#             */
/*   Updated: 2021/01/08 16:24:22 by geliz            ###   ########.fr       */
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
	char		*tmp;

	al = main->alias;
	tmp = sh_strdup(tok->content, main);
	ret = 0;
	while (al)
	{
		if (ft_strcmp(al->name, tmp) == 0)
		{
			ft_strdel(&tmp);
			tmp = sh_strdup(al->command, main);
			if (ft_strcmp(al->command, tok->content) == 0 && al->recurs == 1)
			{
				ret = 0;
				al = NULL;
			}
			else
			{
				ret = 1;
				al->recurs = 1;
				al = main->alias;
			}
		}
		else
			al = al->next;
	}
	if (ret == 1)
	{
		ft_strdel(&tok->content);
		tok->content = tmp;
	}
	else
		ft_strdel(&tmp);
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
