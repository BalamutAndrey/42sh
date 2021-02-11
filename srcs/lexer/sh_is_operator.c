/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_is_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:27:49 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 15:23:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_lexer_bg_check_sep_change(t_token *tok, t_main *main)
{
	ft_strdel(&tok->content);
	tok->content = sh_strdup(";", main);
}

void	sh_lexer_bg_tok_change(t_token *tok, t_token *prev, t_main *main)
{
	if (!prev && ft_strcmp(tok->content, "&") == 0)
	{
		sh_lexer_bg_check_sep_change(tok, main);
		return ;
	}
	if (!prev)
		return ;
	prev->next = tok->next;
	if (ft_strcmp(tok->content, "&") == 0)
		main->bg = true;
	ft_strdel(&tok->content);
	tok->next = NULL;
	free(tok);
}

void	sh_lexer_bg_check(t_main *main)
{
	t_token	*tok;
	t_token	*prev;

	tok = main->token;
	prev = NULL;
	if (!tok)
		return ;
	while (tok)
	{
		if (tok->type == SEPARATOR)
		{
			if (tok->next->type != NEWLINE &&
			ft_strcmp(tok->content, "&") == 0)
				sh_lexer_bg_check_sep_change(tok, main);
			else if (tok->next->type == NEWLINE && !tok->next->next)
				sh_lexer_bg_tok_change(tok, prev, main);
		}
		prev = tok;
		tok = tok->next;
	}
}

int		sh_is_operator(char *str)
{
	if (!ft_strncmp(str, "<<-", 3))
		return (3);
	if (!ft_strncmp(str, "&&", 2) || !ft_strncmp(str, "||", 2)
		|| !ft_strncmp(str, ";;", 2) || !ft_strncmp(str, "<<", 2)
		|| !ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<&", 2)
		|| !ft_strncmp(str, ">&", 2) || !ft_strncmp(str, "<>", 2)
		|| !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '|' || *str == ';' || *str == '>' || *str == '<' ||
			*str == '&' || *str == '(' || *str == ')')
		return (1);
	else
		return (0);
}

int		sh_is_it_io_redirect_operator(char *str)
{
	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<&", 2)
		|| !ft_strncmp(str, ">&", 2) || !ft_strncmp(str, "<>", 2)
		|| !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '>' || *str == '<')
		return (1);
	else
		return (0);
}
