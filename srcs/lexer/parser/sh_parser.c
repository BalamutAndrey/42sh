/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2021/02/07 17:19:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_lexer_start(t_main *main)
{
	while (main->cursor_line_curr < main->cursor_line)
	{
		ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), main->fd);
		main->cursor_line_curr++;
	}
	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	sh_parser(main);
	return (true);
}

void	sh_parser_prompt(t_main *main, int *f_err, int *h_err)
{
	if (!main->prompt && !main->heredoc)
		sh_check_slash(main);
	if (!main->prompt && !main->heredoc)
		sh_check_quotes(main);
	if (!main->prompt && !main->heredoc)
		sh_check_pipe(main);
	if (!main->prompt && !main->heredoc)
		*f_err = sh_check_fbraces(main);
	if (!main->prompt || !ft_strcmp(main->prompt, "Heredoc"))
	{
		if ((*h_err = sh_check_heredoc(main)) == -2)
			ft_fprintf(STDOUT_FILENO, "Heredoc error no here_end token\n");
	}
}

void	sh_parser(t_main *main)
{
	int		empty;
	int		here_err;
	int		fbrace_err;

	empty = sh_is_str_empty(main->ks);
	sh_parser_prompt(main, &here_err, &fbrace_err);
	if (!main->prompt && empty == 0 && here_err != -2 && fbrace_err != 1)
	{
		sh_lexer(main);
		sh_lexer_bg_check(main);
		sh_lexer_tree_new(main);
		if (main->tree_first != NULL)
			sh_exec_struct_create(main);
		sh_exec_bg_check(main->exec_first, main);
		if (main->exec_first != NULL)
			sh_exec(main, main->exec_first);
		ft_strdel(&main->ks_res);
		ft_strdel(&main->alias_cont);
		main->alias_error = NULL;
		sh_alias_recurs_erase(main);
	}
}
