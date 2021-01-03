/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:13:46 by eboris            #+#    #+#             */
/*   Updated: 2021/01/03 19:08:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"
#include <signal.h>

int		sh_is_whitespace_or_tab(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		sh_find_end_of_token(int i, char *str)
{
	while (str[i] != '\0' && str[i] != '\n' &&
		!sh_is_whitespace_or_tab(str[i]) && !sh_is_operator(&str[i]))
	{
		if (str[i] == '\'' && (i == 0 || sh_is_protected(str, i) == 0))
			i = sh_find_closing_single_quotes(i, str);
		else if (str[i] == '"' && (i == 0 || sh_is_protected(str, i) == 0))
			i = sh_find_closing_double_quotes(i, str);
		else if (str[i] != '\0')
			i++;
	}
	return (i);
}

int		sh_check_end_of_token_position(char *str, int *io_nbr_flag)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (sh_is_it_io_redirect_operator(&str[i]) > 0)
			*io_nbr_flag = 1;
		else
			i = sh_find_end_of_token(i, str);
	}
	else if ((i = sh_is_operator(str)) > 0)
		return (i);
	else
		i = sh_find_end_of_token(i, str);
	return (i);
}

void	sh_lexer_hub(t_main *main, t_token *token)
{
	int		i;
	int		j;
	int		io_nbr_flag;
	int		fin;

	i = 0;
	j = 0;
	if (main->heredoc)
		fin = main->heredoc->here_start - 1;
	else
		fin = ft_strlen(main->ks);
	while (j < fin)
	{
		j += i;
		while (sh_is_whitespace_or_tab(main->ks[j]))
			j++;
		io_nbr_flag = 0;
		i = sh_check_end_of_token_position(&main->ks[j], &io_nbr_flag);
		token->next = sh_check_type_and_add_token(&main->ks[j], i, io_nbr_flag,
			main);
		token = token->next;
	}
}

void	tmp_add_alias(t_main *main)
{
	main->alias = sh_memalloc(sizeof(t_alias), main);
	main->alias->next = NULL;
	main->alias->name = ft_strdup("aa");
	main->alias->command = ft_strdup("echo 123");
}

int		sh_lexer(t_main *main)
{
	t_token	*first;

	tmp_add_alias(main);
	first = sh_new_token(0, NULL, main);
	sh_lexer_hub(main, first);
	main->token = first->next;
	free(first);
	first = NULL;
/*	if (sh_lexer_alias_check(main) == 1)
	{
		//sh_delete_trash
		return (1);
	}
	else if (main->ks_res)
		{
			ft_strdel(&main->ks);
			main->ks = sh_strdup(main->ks_res, main);
			ft_strdel(&main->ks_res);
//			tmp = main->ks_res;
//			main->ks_res = main->ks;
//			main->ks = tmp;
//			tmp = NULL;
//			main->ks = main->ks_res; //временно тут, будем еще думать
		}*/
	if (main->heredoc)
		sh_add_heredoc_content(main);
	sh_quote_remove(main, main->token);
	return (0);
}
