/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:14:11 by geliz             #+#    #+#             */
/*   Updated: 2021/02/12 15:49:20 by eboris           ###   ########.fr       */
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
		main_tok = main_tok->next;
	}
	main->ks_res = ret;
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
			if ((ft_strcmp(al->command, tok->content) == 0 &&
				al->recurs == 1) || al->recurs == 2)
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
	if (tok->next && tok->next->type == WORD &&	ft_strlen(tok->content) > 0 &&
	tok->content[ft_strlen(tok->content) - 1] == ' ')
	{
		if (sh_lexer_alias_selection(main, tok->next) == 1)
			sh_alias_space_next_token_check(main, tok->next);
	}
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
				if (flag == 1)
					sh_alias_space_next_token_check(main, tok);
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
	sh_alias_recurs_change(main);
	if (flag == 1)
		sh_lexer_alias_change(main);
	return (flag);
}
