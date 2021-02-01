/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:47:11 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 18:49:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sf_fg_resume(t_main *main, int32_t pid)
{
	tcsetattr(main->fd, TCSANOW, &main->t_start);
	kill(pid, SIGCONT);
	main->cpid = pid;
}
