/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:49:12 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 19:09:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_exit(t_exec *exec, t_main *main)
{
	int	code;
	if (exec && exec->argv[1])
	{
		code = ft_atoi(exec->argv[1]);
	}
	else
	{
		code = 0;
	}
	sh_term_restore(main);
	sh_remove_struct(&main);
	exit(code);
}

void	sh_exit_error(t_main *main)
{
	sh_term_restore(main);
	sh_remove_struct(&main);
	exit(1);
}