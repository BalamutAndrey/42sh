/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:08:03 by geliz             #+#    #+#             */
/*   Updated: 2021/02/01 18:57:03 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_std_in_out_pipe(t_exec *exec, int fd[2], int fd2[2], t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		sh_check_variables(exec, main);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		dup2(fd2[1], STDOUT_FILENO);
		close(fd2[0]);
		sh_standart_exec(exec, main);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		main->cpid = pid;
		if (exec->next && exec->next->pipe == true)
			sh_exec_piped_commands(exec->next, main);
		waitpid(pid, &status, 0);
		exec->exit_s = status;
		main->cpid = -1;
//		sh_signal_status(status, pid);
	}
}

void	sh_stdin_pipe(t_exec *exec, int fd[2], t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		sh_check_variables(exec, main);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		sh_standart_exec(exec, main);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		main->cpid = pid;
		waitpid(pid, &status, 0);
		exec->exit_s = status;
		main->cpid = -1;
//		sh_signal_status(status, pid);
	}
}

void	sh_stdout_pipe(t_exec *exec, int fd[2], t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		sh_check_variables(exec, main);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		sh_standart_exec(exec, main);
	}
	else
	{
		main->cpid = pid;
		if (exec->next && exec->next->pipe == true)
			sh_exec_piped_commands(exec->next, main);
		waitpid(pid, &status, 0);
		exec->exit_s = status;
		main->cpid = -1;
//		sh_signal_status(status, pid);
	}
}

void	fill_pipe(int fd[2], int str_fd[2])
{
	fd[0] = str_fd[0];
	fd[1] = str_fd[1];
}

void	sh_exec_piped_commands(t_exec *exec, t_main *main)
{
	sh_change_envvars_in_exec(main, exec);
	if (exec->pipe == false && exec->next && exec->next->pipe == true)
	{
		pipe(exec->pipefd);
		fill_pipe(exec->next->pipefd, exec->pipefd);
		sh_stdout_pipe(exec, exec->pipefd, main);
	}
	if (exec->pipe == true && exec->next && exec->next->pipe == true)
	{
		pipe(exec->next->pipefd);
		sh_std_in_out_pipe(exec, exec->pipefd, exec->next->pipefd, main);
	}
	if (exec->pipe == true && (!exec->next || exec->next->pipe == false))
		sh_stdin_pipe(exec, exec->pipefd, main);
}
