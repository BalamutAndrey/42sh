/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:27:09 by eboris            #+#    #+#             */
/*   Updated: 2021/02/13 20:44:43 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_signal_set(void)
{
	signal(SIGWINCH, sh_sig_screen_resize);
	signal(SIGINT, sh_sig_ctrl_c);
	signal(SIGQUIT, sh_sig_ctrl_c);
	signal(SIGTSTP, sh_sig_ctrl_z);
}

void	sh_signal_status(int status, pid_t pid)
{
	if (!WIFEXITED(status))
	{
		if (status == SIGSEGV)
		{
			ft_fprintf(STDERR_FILENO, "Segmentation fault\n");
			kill(pid, 1);
		}
		else if (status == SIGBUS)
		{
			ft_fprintf(STDERR_FILENO, "Bus error\n");
			kill(pid, 1);
		}
		else if (status == SIGABRT)
		{
			ft_fprintf(STDERR_FILENO, "Abort trap\n");
			kill(pid, 1);
		}
		else if (status == SIGFPE)
		{
			ft_fprintf(STDERR_FILENO, "Floating point exception\n");
			kill(pid, 1);
		}
	}
}
