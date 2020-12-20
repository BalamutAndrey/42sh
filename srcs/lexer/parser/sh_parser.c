/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/12/20 14:35:47 by geliz            ###   ########.fr       */
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

int		sh_is_it_protected(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	while (i > 0 && str[i - 1] == '\\')
	{
		i--;
		j++;
	}
	if (j % 2 == 0)
		return (0);
	else
		return (1);
}

int		sh_is_str_empty(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		sh_check_fbraces(t_main *main)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (main->ks[i])
	{
		if (main->ks[i] == '{' && sh_is_protected(main->ks, i) == 0)
			count++;
		if (main->ks[i] == '}' && sh_is_protected(main->ks, i) == 0 && count > 0)
			count--;
		i++;
	}
	if (count > 0)
	{
		ft_fprintf(STDERR_FILENO, "42sh: Bad substitution\n");
		return (1);
//		main->prompt = sh_strdup("fquotes", main);
	}
	return (0);
}

void	sh_parser(t_main *main)
{
	int		empty;
	int		here_err;
	int		fbrace_err;

	empty = sh_is_str_empty(main->ks);
	if (!main->prompt && !main->heredoc)
		sh_check_quotes(main);
	if (!main->prompt && !main->heredoc)
		sh_check_slash(main);
	if (!main->prompt && !main->heredoc)
		sh_check_pipe(main);
	if (!main->prompt && !main->heredoc)
		fbrace_err = sh_check_fbraces(main);
	if (!main->prompt || !ft_strcmp(main->prompt, "Heredoc"))
	{
		if ((here_err = sh_check_heredoc(main)) == -2)
			ft_fprintf(STDOUT_FILENO, "Heredoc error no here_end token\n");
	}
	if (!main->prompt && empty == 0 && here_err != -2 && fbrace_err != 1)
	{
		sh_lexer(main);
		sh_lexer_tree_new(main);
		if (main->tree_first != NULL)
			sh_exec_struct_create(main);
		if (main->exec_first != NULL)
			sh_exec(main, main->exec_first);
	}
}
