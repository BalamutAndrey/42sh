/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2021/01/08 13:36:58 by geliz            ###   ########.fr       */
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
	char	*str;

	i = 0;
	count = 0;
	str = main->ks_res ? main->ks_res : main->ks;
	while (str[i])
	{
		if (str[i] == '{' && sh_is_protected(str, i) == 0)
			count++;
		if (str[i] == '}' && sh_is_protected(str, i) == 0 && count > 0)
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
//	int		alias;
//	int		i;

	empty = sh_is_str_empty(main->ks);
//	alias = 0;
/*	if (main->ks_tmp && ft_strcmp(main->ks, main->ks_tmp) != 0)
	{
		i = 0;
		while (main->ks[i] == main->ks_tmp[i])
			i++;
		main->ks_res = sh_strjoin_arg(main, "%f %s", main->ks_res, &main->ks[i]);
	}*/
//	ft_printf("main->ks = %s\nmain->ks_res = %s\n", main->ks, main->ks_res);
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
		ft_strdel(&main->ks_res);
	}
	ft_strdel(&main->alias_cont);
	main->alias_error = NULL;
//	if (alias == 1 && !main->ks_tmp && main->prompt)
//		main->ks_tmp = sh_strdup(main->ks, main);
}
