/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:21:19 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 16:22:45 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_READ_H
# define SH_READ_H

/*
** sh_readline.c
*/
void	sh_readline(t_main *main);
void	sh_rl_reset_line(t_main *main);
void	sh_rl_check_prompt_start(t_main *main);
void	sh_print_prompt(t_main *main);

/*
** sh_readline_readkey.c
*/
bool	sh_readline_readkey(t_main *main);
void	sh_readline_readkey_add(t_main *main, uint64_t buf);

/*
** sh_readline_end.c
*/
bool	sh_readline_end(t_main *main);
void	sh_readline_clear(t_main *main);

/*
** sh_isprint.c
*/
bool	sh_isprint(int64_t c);

/*
** sh_cursor.c
*/
void	sh_reprint_ks(t_main *main);
void	sh_reprint_ks_2(t_main *main);
void	sh_reprint_ks_3(t_main *main);
void	sh_cursor_plus(t_main *main);
void	sh_cursor_minus(t_main *main);

/*
** sh_cursor_math.c
*/
void	sh_cursor_math(t_main *main);
void	sh_cursor_math_curr(t_main *main);
void	sh_cursor_math_if(t_main *main, uint64_t *i, uint64_t *l, uint64_t *n);
void	sh_cursor_math_elseif(t_main *main, uint64_t *i, uint64_t *l,
		uint64_t *n);
void	sh_cursor_math_else(uint64_t *i, uint64_t *n);

/*
** sh_history.c
*/
void	sh_history_add(t_main *main);
void	sh_history_create(t_main *main);
void	sh_history_newlist(t_main *main);

/*
** sh_history_read.c
*/
void	sh_history_read(t_main *main, char k);
void	sh_history_read_up(t_main *main);
void	sh_history_read_down(t_main *main);

#endif
