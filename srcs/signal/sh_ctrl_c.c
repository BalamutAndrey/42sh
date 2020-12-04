/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:16:34 by eboris            #+#    #+#             */
/*   Updated: 2020/11/29 14:44:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_ctrl_c(int a)
{
	extern t_main	*g_main;

	(void)a;
	tcsetattr(g_main->fd, TCSANOW, &g_main->t_curr);
	if (g_main->cpid != -1)
	{
		kill(g_main->cpid, 1);
		g_main->cpid = -1;
		ft_putstr_fd(tgetstr("do", NULL), g_main->fd);
		ft_putstr_fd(tgetstr("cr", NULL), g_main->fd);
	}
	else
	{
		sh_sig_ctrl_c_ks(g_main);
	}
}

void	sh_sig_ctrl_c_ks(t_main *g_main)
{
	while (g_main->cursor_line_curr < g_main->cursor_line)
	{
		ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), g_main->fd);
		g_main->cursor_line_curr++;
	}
	ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), g_main->fd);
	if (g_main->prompt != NULL)
		sh_new_prompt(g_main);
	if (g_main->ks_temp != NULL)
		ft_strdel(&g_main->ks_temp);
	ft_bzero(g_main->ks, MAX_KS_LEN);
	g_main->ks_len = 0;
	g_main->cursor = 0;
	sh_cursor_math(g_main);
	sh_reprint_ks(g_main);
	g_main->hist_curr = g_main->hist_end;
}

void	sh_new_prompt(t_main *g_main)
{
	ft_strdel(&g_main->prompt);
	g_main->prompt_len = 3;
	if (g_main->user)
		g_main->prompt_len = g_main->prompt_len + ft_strlen(g_main->user) + 1;
	else
		g_main->prompt_len = g_main->prompt_len + 8;
}
