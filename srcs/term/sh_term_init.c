/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:33:48 by eboris            #+#    #+#             */
/*   Updated: 2021/02/07 15:37:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	tmp_erm_func(t_main *main)
{
	while (tcgetpgrp(STDOUT_FILENO) != (main->pid = getpgrp()))
		kill(-main->pid, SIGTTIN);
	main->pid = getpid();
	if (setpgid(main->pid, main->pid) < 0)
		ft_fprintf(2, "Couldn't put shell in its own process group");
	if (tcsetpgrp(STDOUT_FILENO, main->pid) == -1)
		ft_fprintf(2, "Couldn't get control of terminal");
	if (tcgetattr(STDOUT_FILENO, &main->t_curr) == -1)
		ft_fprintf(2, "Failed to save terminal original state");
}

bool	sh_term_init(t_main *main)
{
	if ((getenv("TERM") == NULL) ||
			(main->term_name = ft_strdup(getenv("TERM"))) == NULL)
		sh_error_init(1, main);
	if (tgetent(NULL, main->term_name) <= 0)
		sh_error_init(2, main);
	main->fd = STDOUT_FILENO;
	tcgetattr(main->fd, &main->t_start);
	ft_memcpy(&main->t_curr, &main->t_start, sizeof(main->t_start));
	main->t_curr.c_lflag &= ~(ICANON | ECHO | ECHONL | IEXTEN);
	main->t_curr.c_cc[VMIN] = 1;
	main->t_curr.c_cc[VTIME] = 0;
	if (tcsetattr(main->fd, TCSANOW, &main->t_curr) == -1)
		sh_error_init(4, main);
	tmp_erm_func(main);
	ft_putstr_fd(tgetstr("cl", NULL), main->fd);
	ft_putstr_fd(tgetstr("ti", NULL), main->fd);
	ft_putstr_fd(tgetstr("vs", NULL), main->fd);
	sh_ioctl(main);
	return (false);
}

void	sh_ioctl(t_main *main)
{
	struct winsize w;

	ioctl(main->fd, TIOCGWINSZ, &w);
	main->term_col = w.ws_col;
	main->term_row = w.ws_row;
}

void	sh_term_restore(t_main *main)
{
	ft_putstr_fd(tgetstr("te", NULL), main->fd);
	ft_putstr_fd(tgetstr("ve", NULL), main->fd);
	tcsetattr(main->fd, TCSANOW, &main->t_start);
	close(main->fd);
}
