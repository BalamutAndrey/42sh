/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_shift_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:10:45 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 18:46:30 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_shift_right(t_main *main)
{
	if (main->cursor_sel == false && main->cursor < main->ks_len)
	{
		main->cursor_sel = true;
		main->cursor_sel_start = (main->cursor);
		main->cursor_sel_end = (main->cursor);
		sh_cursor_plus(main);
	}
	else if (main->cursor_sel == false && main->cursor == main->ks_len)
	{
		main->cursor_sel = true;
		main->cursor_sel_start = main->ks_len;
		main->cursor_sel_end = main->ks_len;
		sh_reprint_ks(main);
	}
	else if (main->cursor_sel == true &&
	main->cursor_sel_end == (main->cursor - 1) && main->cursor < main->ks_len)
	{
		main->cursor_sel_end = (main->cursor);
		sh_cursor_plus(main);
	}
	else
		sh_key_shift_right_2(main);
}

void	sh_key_shift_right_2(t_main *main)
{
	if (main->cursor_sel == true &&
	main->cursor_sel_end == (main->cursor - 1) && main->cursor == main->ks_len)
	{
		sh_reprint_ks(main);
	}
	else if (main->cursor_sel == true && main->cursor_sel_start == main->cursor)
	{
		main->cursor_sel_start = main->cursor + 1;
		sh_cursor_plus(main);
	}
	else if (main->cursor_sel == true &&
	main->cursor_sel_end != (main->cursor - 1) && main->cursor < main->ks_len)
	{
		main->cursor_sel_start = (main->cursor);
		main->cursor_sel_end = (main->cursor);
		sh_cursor_plus(main);
	}
	else if (main->cursor_sel == true &&
	main->cursor_sel_end != (main->cursor - 1) && main->cursor == main->ks_len)
	{
		main->cursor_sel_start = main->ks_len;
		main->cursor_sel_end = main->ks_len;
		sh_reprint_ks(main);
	}
}
