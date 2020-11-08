/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_shift_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:08:57 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 18:48:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_shift_left(t_main *main)
{
	if (main->cursor_sel == false && main->cursor > 0)
	{
		main->cursor_sel = true;
		main->cursor_sel_start = (main->cursor - 1);
		main->cursor_sel_end = (main->cursor - 1);
		sh_cursor_minus(main);
	}
	else if (main->cursor_sel == false && main->cursor == 0)
	{
		main->cursor_sel = true;
		main->cursor_sel_start = 0;
		main->cursor_sel_end = 0;
		sh_reprint_ks(main);
	}
	else if (main->cursor_sel == true &&
		main->cursor_sel_start == main->cursor && main->cursor > 0)
	{
		main->cursor_sel_start = (main->cursor - 1);
		sh_cursor_minus(main);
	}
	else
		sh_key_shift_left_2(main);
}

void	sh_key_shift_left_2(t_main *main)
{
	if (main->cursor_sel == true &&
		main->cursor_sel_start == main->cursor && main->cursor == 0)
	{
		sh_reprint_ks(main);
	}
	else if (main->cursor_sel == true &&
		main->cursor_sel_end == (main->cursor - 1))
	{
		main->cursor_sel_end = main->cursor - 2;
		sh_cursor_minus(main);
	}
	else if (main->cursor_sel == true &&
		main->cursor_sel_start != main->cursor && main->cursor > 0)
	{
		main->cursor_sel_start = (main->cursor - 1);
		main->cursor_sel_end = (main->cursor - 1);
		sh_cursor_minus(main);
	}
	else if (main->cursor_sel == true &&
		main->cursor_sel_start != main->cursor && main->cursor == 0)
	{
		main->cursor_sel_start = 0;
		main->cursor_sel_end = 0;
		sh_reprint_ks(main);
	}
}
