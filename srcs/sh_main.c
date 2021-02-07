/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2021/02/06 21:43:23 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_main	*g_main;

// Delete me after test! 
// void	temp_alias(t_main *main)
// {
// 	t_alias *first;
// 	t_alias *end;

// 	first = sh_memalloc(sizeof(t_alias), main);
// 	first->name = sh_strdup("ll", main);
// 	first->command = sh_strdup("2>&1 ls -l -F", main);
	
// 	end = sh_memalloc(sizeof(t_alias), main);
// 	end->name = sh_strdup("aa", main);
// 	end->command = sh_strdup("2>&1 ls -l -a -F | wc -c", main);

// 	first->next = end;
// 	end->next = NULL;

// 	main->alias = first;
// 	main->alias_end = end;
// }

void	tmp_term_init(t_main *main)
{
	pid_t	pid;
	
	pid = getpid();
	setpgid(pid, pid);
	tcsetpgrp(STDOUT_FILENO, pid);
	tcgetattr(STDOUT_FILENO, &main->t_start);
}

int	main(int argc, char **argv, char **env)
{
	t_main			*main;
	extern t_main	*g_main;

	g_main = sh_add_main_struct(env);
	main = g_main;
	if (sh_term_check_errors_start(argc, argv, env))
		exit(0);
	sh_term_init(main);
	tmp_term_init(main);
	sh_signal_set();
	sh_copy_envp(main);
	sh_path(main);

	// FOR TEST ONLY !!!
	// temp_alias(main);

	sh_readline(main);
	sh_term_restore(main);
	sh_remove_struct(&main);
	return (0);
}
