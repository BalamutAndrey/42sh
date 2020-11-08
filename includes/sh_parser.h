/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:06:56 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 15:20:06 by geliz            ###   ########.fr       */
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

#endif
