/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:38:41 by eboris            #+#    #+#             */
/*   Updated: 2020/10/31 19:19:34 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

/*
** sh_lexer.c
*/
int		sh_lexer(t_main *main);
void	sh_lexer_hub(t_main *main, t_token *token);
int		sh_check_end_of_token_position(char *str, int *io_nbr_flag);
int		sh_find_end_of_token(int i, char *str);
int		sh_is_whitespace_or_tab(char c);
/*
**	sh_lexer_find_quotes.c
*/
int		sh_find_closing_single_quotes(int i, char *str);
int		sh_find_closing_double_quotes(int i, char *str);
/*
**	sh_is_operator.c
*/
int		sh_is_operator(char *str);
int		sh_is_it_io_redirect_operator(char *str);
/*
**	sh_check_and_add_token.c
*/
t_token	*sh_check_type_and_add_token(char *str, int i, int io_nbr_flag,
	t_main *main);
/*
**	sh_add_operator_token.c
*/
void	sh_add_operator_token(t_token *token);
void	sh_add_operator_token_part_two(t_token *token);
/*
**	sh_token_struct.c
*/
t_token	*sh_new_token(int type, char *content, t_main *main);
void	sh_remove_token_list(t_token *token);
/*
**	sh_add_heredoc_content.c
*/
void	sh_add_heredoc_content(t_main *main);
void	sh_delete_heredoc_struct(t_main *main);
/*
**	sh_quote_remove.c
*/
void	sh_quote_remove(t_main *main, t_token *token);
void	sh_find_envvar(t_token *token, t_main *main);
void	sh_find_and_remove_quotes(t_main *main, t_token *token);
/*
**	sh_token_quote_remove.c
*/
int		sh_squotes_remove(t_token *token, int i, t_main *main);
int		sh_dquotes_remove(t_token *token, int i, t_main *main);
int		sh_dslashes_remove(int i, int end, t_token *token, t_main *main);
/*
**	sh_envvar_struct.c
*/
int		sh_add_envvar(int type, int i, t_main *main, t_token *token);
void	sh_delete_envvars(t_envvar *envvar);
/*
**	sh_quote_remove_funcs.c
*/
void	sh_remove_char(int i, t_token *token, t_main *main);
int		sh_is_protected(char *str, int i);

#endif
