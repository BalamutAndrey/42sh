/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_t_quote_remove.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:46:32 by geliz             #+#    #+#             */
/*   Updated: 2020/12/20 18:56:52 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_dslashes_remove(int i, int end, t_token *t, t_main *main)
{
	while (i < end)
	{
		if (t->content[i] == '\\' && t->content[i + 1] == '\\')
		{
			sh_remove_char(i, t, main);
			end--;
		}
		i++;
	}
	return (end);
}

int		sh_dquotes_remove(t_token *t, int i, t_main *main)
{
	int		tmp;

	tmp = i;
	sh_remove_char(i, t, main);
	while (t->content[i] != '\0')
	{
		if (t->content[i] == '\\' &&
			(t->content[i + 1] == '\"' || t->content[i + 1] == '$') &&
			sh_is_protected(t->content, i) == 0)
		{
			sh_remove_char(i, t, main);
			i++;
		}
		else if (t->content[i] == '$' &&
			sh_is_protected(t->content, i) == 0 &&
			(ft_isalpha(t->content[i + 1]) == 1 || t->content[i + 1] == '{'))
			i = sh_add_envvar(1, i, main, t);
		else if (t->content[i] == '\"' && sh_is_protected(t->content, i) == 0)
			break ;
		else
			i++;
	}
	sh_remove_char(i, t, main);
	i = sh_dslashes_remove(tmp, i, t, main);
	return (i);
}

int		sh_squotes_remove(t_token *t, int i, t_main *main)
{
	sh_remove_char(i, t, main);
	while (t->content[i] != '\'')
		i++;
	sh_remove_char(i, t, main);
	return (i);
}
