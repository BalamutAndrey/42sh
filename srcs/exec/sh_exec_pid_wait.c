/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pid_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:33:54 by geliz             #+#    #+#             */
/*   Updated: 2021/02/13 20:47:40 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exec_pid_wait(t_main *main, t_exec *exec)
{
	int		status;
	int		ret;

	ret = waitpid(main->cpid, &status, WUNTRACED);
	sh_signal_status(status, main->cpid);
	if (WIFEXITED(status) != 0)
	{
		exec->exit_s = WEXITSTATUS(status);
	}
	else if (WIFSTOPPED(status))
		sh_sig_ctrl_z(0);
	else
		exec->exit_s = 1;
	setpgid(0, 0);
	tcsetpgrp(STDOUT_FILENO, main->pid);
}
