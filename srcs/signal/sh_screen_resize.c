/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_screen_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:28:01 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 13:19:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_screen_resize(int a)
{
	extern t_main	*g_main;

	(void)a;
	sh_ioctl(g_main);
	ft_putstr_fd(tgetstr("cl", NULL), g_main->fd);
	sh_cursor_math(g_main);
	sh_reprint_ks(g_main);
}
