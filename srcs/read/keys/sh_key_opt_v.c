/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:10:41 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:37:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

uint64_t	sh_key_opt_v_select(t_main *main)
{
	uint64_t	i;
	uint64_t	n;

	i = main->cursor;
	n = 0;
	main->cursor_sel_start = i;
	main->cursor_sel_end = i;
	while (main->cursor_sel_text[n] != '\0' && (i < MAX_KS_LEN))
	{
		main->ks[i] = main->cursor_sel_text[n];
		i++;
		n++;
		main->ks_len++;
		main->cursor_sel_end++;
		sh_cursor_plus(main);
	}
	main->cursor_sel_end--;
	return (i);
}

void		sh_key_opt_v_paste(t_main *main, uint64_t i, char *temp)
{
	uint64_t	n;

	n = 0;
	while (temp[n] != '\0' && (i < MAX_KS_LEN))
	{
		main->ks[i] = temp[n];
		i++;
		n++;
	}
}

void		sh_key_opt_v(t_main *main)
{
	uint64_t	i;
	uint64_t	n;
	char		*temp;

	n = 0;
	temp = sh_strnew(MAX_KS_LEN, main);
	if (main->cursor_sel_text[0] != '\0')
	{
		i = main->cursor;
		while (main->ks[i] != '\0')
		{
			temp[n] = main->ks[i];
			main->ks[i] = '\0';
			i++;
			n++;
		}
		i = sh_key_opt_v_select(main);
		sh_key_opt_v_paste(main, i, temp);
	}
	ft_strdel(&temp);
	main->cursor_sel = true;
	sh_reprint_ks(main);
}
