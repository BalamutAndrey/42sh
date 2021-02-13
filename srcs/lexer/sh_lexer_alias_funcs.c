/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:40:58 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 19:15:40 by geliz            ###   ########.fr       */
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

int		sh_lexer_alias_selection_check(t_alias *al, t_token *tok, char *tmp,
	t_main *main)
{
	int		ret;

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
				return (0);
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
	return (ret);
}

int		sh_lexer_alias_selection(t_main *main, t_token *tok)
{
	t_alias		*al;
	int			ret;
	char		*tmp;

	al = main->alias;
	tmp = sh_strdup(tok->content, main);
	ret = sh_lexer_alias_selection_check(al, tok, tmp, main);
	if (ret == 1)
	{
		ft_strdel(&tok->content);
		tok->content = tmp;
	}
	else
		ft_strdel(&tmp);
	return (ret);
}
