/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 18:41:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_main	*g_main;

int	main(int argc, char **argv, char **env)
{
	t_main			*main;
	extern t_main	*g_main;

	g_main = sh_add_main_struct(env);
	main = g_main;
	if (sh_term_check_errors_start(argc, argv, env))
		exit(0);
	sh_term_init(main);
	sh_signal_set();
	sh_copy_envp(main);
	sh_path(main);
	sh_readline(main);
	sh_term_restore(main);
	sh_remove_struct(&main);
	return (0);
}
