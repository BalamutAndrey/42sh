/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:16:02 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 16:22:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_readline(t_main *main)
{
	bool	fin;

	fin = true;
	while (fin == true)
	{
		sh_rl_reset_line(main);
		sh_rl_check_prompt_start(main);
		sh_print_prompt(main);
		sh_cursor_math(main);
		while (fin == true)
		{
			fin = sh_readline_readkey(main);
		}
		fin = sh_readline_end(main);
	}
}

void	sh_rl_reset_line(t_main *main)
{
	main->ks_len = 0;
	main->ks_temp_len = 0;
	main->cursor = 0;
	main->cursor_sel = false;
	main->cursor_sel_start = 0;
	main->cursor_sel_end = 0;
}

void	sh_rl_check_prompt_start(t_main *main)
{
	if (main->prompt == NULL)
	{
		ft_bzero(main->dir, MAX_DIR_LEN);
		ft_bzero(main->ks, MAX_KS_LEN);
		getcwd(main->dir, MAX_DIR_LEN - 1);
		main->ks_len = 0;
	}
	else
	{
		main->ks_temp_len = ft_strlen(main->ks);
		main->ks_temp = ft_strnew(MAX_KS_LEN);
		ft_strcpy(main->ks_temp, main->ks);
		ft_bzero(main->ks, MAX_KS_LEN);
		if ((ft_strcmp(main->prompt, "slash") != 0) &&
		(ft_strcmp(main->prompt, "Pipeline") != 0))
			main->ks_temp[main->ks_temp_len] = '\n';
		else if (ft_strcmp(main->prompt, "slash") == 0)
			main->ks_temp[main->ks_temp_len - 1] = '\0';
	}
}

void	sh_print_prompt(t_main *main)
{
	main->prompt_len = 3;
	if (main->prompt == NULL)
	{
		if (main->user)
		{
			ft_fprintf(STDOUT_FILENO, "%s ", main->user);
			main->prompt_len = main->prompt_len + ft_strlen(main->user) + 1;
		}
		else
		{
			ft_fprintf(STDOUT_FILENO, "%03ix%03i ", main->term_col,
			main->term_row);
			main->prompt_len = main->prompt_len + 8;
		}
		ft_fprintf(STDOUT_FILENO, "$> ");
	}
	else
	{
		main->prompt_len = main->prompt_len + ft_strlen(main->prompt);
		ft_fprintf(STDOUT_FILENO, "%s > ", main->prompt);
	}
}
