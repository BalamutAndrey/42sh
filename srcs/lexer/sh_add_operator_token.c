/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_add_operator_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:33:42 by geliz             #+#    #+#             */
/*   Updated: 2020/10/30 19:31:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_operator_token_part_two(t_token *token)
{
	if (!ft_strcmp(token->content, ">|"))
		token->type = CLOBBER;
	else if (!ft_strcmp(token->content, ";"))
		token->type = SEPARATOR;
	else if (!ft_strcmp(token->content, "!"))
		token->type = BANG;
	else if (!ft_strcmp(token->content, "{"))
		token->type = LBRACE;
	else if (!ft_strcmp(token->content, "}"))
		token->type = RBRACE;
	else if (!ft_strcmp(token->content, "|"))
		token->type = PIPELINE;
	else if (!ft_strcmp(token->content, "(") || !ft_strcmp(token->content, ")"))
		token->type = NONE;
	else if (!ft_strcmp(token->content, "<"))
		token->type = LESS;
	else if (!ft_strcmp(token->content, ">"))
		token->type = GREAT;
}

void	sh_add_operator_token(t_token *token)
{
	if (!ft_strcmp(token->content, "<<-"))
		token->type = DLESSDASH;
	else if (!ft_strcmp(token->content, "&&"))
		token->type = AND_IF;
	else if (!ft_strcmp(token->content, "||"))
		token->type = OR_IF;
	else if (!ft_strcmp(token->content, ";;"))
		token->type = DSEMI;
	else if (!ft_strcmp(token->content, "<<"))
		token->type = DLESS;
	else if (!ft_strcmp(token->content, ">>"))
		token->type = DGREAT;
	else if (!ft_strcmp(token->content, "<&"))
		token->type = LESSAND;
	else if (!ft_strcmp(token->content, ">&"))
		token->type = GREATAND;
	else if (!ft_strcmp(token->content, "<>"))
		token->type = LESSGREAT;
	else
		sh_add_operator_token_part_two(token);
}
