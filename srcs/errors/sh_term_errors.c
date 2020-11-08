/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:02:39 by eboris            #+#    #+#             */
/*   Updated: 2020/07/08 14:12:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_term_errors_start(uint8_t error)
{
	if (error == 1)
	{
		ft_putstr_fd("21sh: Error. No enviroment.\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("21sh: Error. Not a terminal.\n", 2);
	}
	else if (error == 3)
	{
		ft_putstr_fd("21sh: Error. Out of memory.\n", 2);
	}
}

void	sh_error_init(uint8_t error, t_main *main)
{
	if (error == 1)
	{
		ft_putstr_fd("21sh: Error getenv().", 2);
		ft_putstr_fd(" Failed getting TERM environnement.\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("21sh: Error tgetenv().", 2);
		ft_putstr_fd(" Failed getting TERM environnement (", 2);
		ft_putstr_fd(main->term_name, 2);
		ft_putstr_fd(").\n", 2);
	}
	else if (error == 3)
	{
		ft_putstr_fd("21sh: Error open().", 2);
		ft_putstr_fd(" Failed getting fd.\n", 2);
	}
	else if (error == 4)
	{
		ft_putstr_fd("21sh: Error tcsetattr().", 2);
		ft_putstr_fd(" Failed to set termios.\n", 2);
	}
	sh_remove_struct(&main);
}
