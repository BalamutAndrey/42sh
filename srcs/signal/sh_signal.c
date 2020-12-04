/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:27:09 by eboris            #+#    #+#             */
/*   Updated: 2020/12/04 18:00:19 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_signal_set(void)
{
	signal(SIGWINCH, sh_sig_screen_resize);
	signal(SIGINT, sh_sig_ctrl_c);
	signal(SIGQUIT, sh_sig_ctrl_c);
}

void	sh_signal_status(int status, pid_t pid)
{
	if (!WIFEXITED(status))
	{
		kill(pid, 1);
		if (status == SIGSEGV)
			ft_fprintf(STDERR_FILENO, "Segmentation fault: ");
		else if (status == SIGBUS)
			ft_fprintf(STDERR_FILENO, "Bus error: ");
		else if (status == SIGABRT)
			ft_fprintf(STDERR_FILENO, "Abort trap: ");
		else if (status == SIGFPE)
			ft_fprintf(STDERR_FILENO, "Floating point exception: ");
		ft_fprintf(STDERR_FILENO, "Status code: %i\n", status);
	}
}
