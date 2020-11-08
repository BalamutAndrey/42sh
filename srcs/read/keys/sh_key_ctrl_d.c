/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:41:57 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 17:29:52 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_key_ctrl_d(t_main *main)
{
	if ((main->prompt != NULL) && (ft_strcmp(main->prompt, "Heredoc") == 0) &&
	(main->ks[0] == '\0'))
	{
		main->ks[main->ks_len++] = 4;
		ft_putstr_fd(tgetstr("do", NULL), main->fd);
		ft_putstr_fd(tgetstr("cr", NULL), main->fd);
		return (false);
	}
	else if ((main->ks != NULL) && (main->ks[0] == '\0'))
	{
		ft_fprintf(STDERR_FILENO, "exit\n");
		sh_exit(main, 0);\
	}
	return (true);
}
