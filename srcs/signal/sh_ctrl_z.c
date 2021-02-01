/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:22:48 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 18:44:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_ctrl_z(int a)
{
	extern t_main	*g_main;

	(void)a;
	if (g_main->cpid != -1)
	{
		tcsetattr(g_main->fd, TCSANOW, &g_main->t_curr);
		kill(g_main->cpid, SIGSTOP);
		g_main->cpid = -1;
		ft_putstr_fd(tgetstr("do", NULL), g_main->fd);
		ft_putstr_fd(tgetstr("cr", NULL), g_main->fd);
	}
}
