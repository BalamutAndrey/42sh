/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_alias.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:46:47 by eboris            #+#    #+#             */
/*   Updated: 2021/02/12 15:46:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_lexer_alias_assig_sep_check(int type)
{
	if (type == AND_IF || type == AND_OR || type == SEPARATOR
		|| type == PIPELINE)
		return (1);
	else
		return (0);
}

void	sh_lexer_alias_assig_check(t_token *tok)
{
	int		alias;
	int		fword;

	alias = 0;
	fword = 0;
	while (tok)
	{
		if (tok->type == WORD)
		{
			if (fword == 0 && (ft_strcmp(tok->content, "alias") == 0))
				alias = 1;
			fword++;
		}
		else if (sh_lexer_alias_assig_sep_check(tok->type) == 1)
		{
			fword = 0;
			alias = 0;
		}
		else if ((sh_lexer_alias_is_redir(tok) == 1) && tok->next &&
			tok->next->type == WORD)
			tok = tok->next;
		else if (tok->type == ASSIGNMENT_WORD && alias == 1)
			tok->type = WORD;
		tok = tok->next;
	}
}

void	sh_lex_remove_token(t_main *main)
{
	t_token		*tok;
	t_token		*nxt;
	t_envvar	*env;
	t_envvar	*env_nxt;

	tok = main->token;
	while (tok)
	{
		ft_strdel(&tok->content);
		env = tok->envvar;
		while (env)
		{
			env_nxt = env->next;
			env->str = NULL;
			free(env);
			env = env->next;
		}
		nxt = tok->next;
		free(tok);
		tok = nxt;
	}
}
