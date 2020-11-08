/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline_readkey.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:40:30 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 18:02:19 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_readline_readkey(t_main *main)
{
	bool		fin;
	uint64_t	buf;

	fin = true;
	buf = 0;
	read(0, &buf, 8);
	if (((main->ks_len + main->ks_temp_len) < MAX_KS_LEN) &&
		(sh_isprint(buf) == true))
	{
		sh_readline_readkey_add(main, buf);
	}
	else
	{
		fin = sh_keys(main, buf);
	}
	return (fin);
}

void	sh_readline_readkey_add(t_main *main, uint64_t buf)
{
	uint64_t	i;
	char		*temp;

	main->cursor_sel = false;
	main->cursor_sel_start = 0;
	main->cursor_sel_end = 0;
	if (main->cursor == main->ks_len)
		main->ks[main->ks_len] = buf;
	else
	{
		i = main->cursor - 1;
		temp = ft_strnew(MAX_KS_LEN);
		while (main->ks[++i] != '\0')
			temp[i - main->cursor] = main->ks[i];
		main->ks[main->cursor] = buf;
		i = main->cursor - 1;
		while (temp[(++i) - main->cursor] != '\0')
			main->ks[i + 1] = temp[i - main->cursor];
		ft_strdel(&temp);
	}
	main->ks_len++;
	sh_cursor_plus(main);
}
