/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:06:56 by geliz             #+#    #+#             */
/*   Updated: 2021/02/12 15:53:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

/*
** sh_parser.c
*/
bool		sh_lexer_start(t_main *main);
int			sh_is_str_empty(char *str);
void		sh_parser(t_main *main);
void		sh_alias_recurs_clear(t_alias *al);
/*
** sh_parser_check_quotes.c
*/
void		sh_check_quotes(t_main *main);
void		sh_count_quotes(t_main *main, int cq[2]);
/*
** sh_parser_slash.c
*/
void		sh_check_slash(t_main *main);
/*
** sh_parser_heredoc.c
*/
int			sh_check_heredoc(t_main *main);
void		sh_erase_heredoc_from_ks(t_main *main);
int			sh_is_heredoc_finished(t_main *main);
void		sh_get_heredoc_content(t_main *main);
void		sh_erase_heredoc_content_from_ks(t_main *main, int start, int len);
/*
** sh_parser_heredoc_struct.c
*/
int			sh_create_heredoc_structs(t_main *main);
t_heredoc	*sh_create_heredoc_list(int i, t_main *main);
int			sh_find_heredoc(t_main *main, int i);
void		sh_get_heredoc_info(t_main *main, t_heredoc *here);
/*
** sh_parser_heredoc_delim_correction.c
*/
void		sh_heredoc_delim_correction(t_main *main);
void		sh_find_and_remove_heredoc_quotes(t_heredoc *here, t_main *main);
void		sh_heredoc_remove_char(int i, t_heredoc *here, t_main *main);
/*
** sh_parser_heredoc_quotes_rm.c
*/
int			sh_heredoc_squotes_remove(t_heredoc *here, int i, t_main *main);
int			sh_heredoc_dquotes_remove(t_heredoc *here, int i, t_main *main);
int			sh_heredoc_dslashes_remove(int i, int end, t_heredoc *here,
				t_main *main);
/*
** sh_parser_pipe.c
*/
void		sh_check_pipe(t_main *main);

/*
** sh_parser_funcs.c
*/
void		sh_alias_recurs_erase(t_main *main);
int			sh_check_fbraces(t_main *main);
int			sh_is_str_empty(char *str);
int			sh_is_it_protected(char *str);

#endif
