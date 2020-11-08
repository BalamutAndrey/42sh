/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:35:11 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:24:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_backspace_string(t_main *main)
{
	uint64_t	i;
	char		*temp;

	i = main->cursor;
	temp = ft_strnew(MAX_KS_LEN);
	while (main->ks[i] != '\0')
	{
		temp[i - main->cursor] = main->ks[i];
		i++;
	}
	i = 0;
	sh_cursor_minus(main);
	while (temp[i] != '\0')
	{
		main->ks[main->cursor + i] = temp[i];
		i++;
	}
	main->ks[main->cursor + i] = '\0';
	ft_strdel(&temp);
	main->ks_len--;
}

void	sh_key_backspace(t_main *main)
{
	if ((main->cursor == main->ks_len) && (main->cursor > 0))
	{
		sh_cursor_minus(main);
		main->ks_len--;
		main->ks[main->cursor] = '\0';
	}
	else if (main->cursor > 0)
		sh_key_backspace_string(main);
	sh_reprint_ks(main);
}
