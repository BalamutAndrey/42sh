/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:25:36 by geliz             #+#    #+#             */
/*   Updated: 2020/11/06 18:37:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_redirect_to_file(t_redirect *new, t_main *main)
{
	int		fd;

	sh_redirect_check_chmod(main, new);
	if (new->error >= 0)
	{
		fd = open(new->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		sh_add_opened_fd(main, fd);
		dup2(fd, new->io_num);
	}
}

void	sh_redirect_to_file_append(t_redirect *new, t_main *main)
{
	int		fd;

	sh_redirect_check_chmod(main, new);
	if (new->error >= 0)
	{
		fd = open(new->filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
		sh_add_opened_fd(main, fd);
		dup2(fd, new->io_num);
	}
}

void	sh_redirect_from_file(t_redirect *new, t_main *main)
{
	int		fd;

	sh_redirect_check_chmod(main, new);
	if (new->error >= 0)
	{
		fd = open(new->filename, O_RDONLY);
		sh_add_opened_fd(main, fd);
		dup2(fd, new->io_num);
	}
}
