/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 17:32:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
	else
		ret = sh_new_token(WORD, sh_strsub(str, 0, i, main), main);
	return (ret);
}
