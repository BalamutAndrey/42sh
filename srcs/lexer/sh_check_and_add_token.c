/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/12/06 17:28:08 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int			sh_lexer_check_assig_word(char *str, int i)
{
	int		j;

	j = 0;
	if (str[j] == '=')
		return (0);
	if (ft_isalpha(str[j]) != 1)
		return (0);
	while (j < i)
	{
		if (ft_isalnum(str[j]) == 1 || str[j] == '_' || str[j] == '=')
		{
			if (str[j] == '=')
				return (1);
			j++;
		}
		else
			return (0);
	}
	return (0);
}

t_token		*sh_check_type_and_add_token(char *str, int i, int io_nbr_flag,
	t_main *main)
{
	t_token		*ret;

	if (i == 0)
		ret = sh_new_token(NEWLINE, sh_strdup("<newline>", main), main);
	else if (io_nbr_flag != 0)
		ret = sh_new_token(IO_NUMBER, sh_strsub(str, 0, i, main), main);
	else if (sh_is_operator(str) > 0)
	{
		ret = sh_new_token(NONE, sh_strsub(str, 0, i, main), main);
		sh_add_operator_token(ret);
	}
	else if (sh_lexer_check_assig_word(str, i) == 1)
		ret = sh_new_token(ASSIGNMENT_WORD, sh_strsub(str, 0, i, main), main);
	else
		ret = sh_new_token(WORD, sh_strsub(str, 0, i, main), main);
	return (ret);
}
