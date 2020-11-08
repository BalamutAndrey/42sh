/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_keys.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:56:11 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 16:22:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_KEYS_H
# define SH_KEYS_H

/*
** sh_keys.c
*/
bool		sh_keys(t_main *main, uint64_t buf);
bool		sh_keys_2(t_main *main, uint64_t buf);
bool		sh_keys_3(t_main *main, uint64_t buf);

/*
** sh_key_enter.c
*/
bool		sh_key_enter(t_main *main);

/*
** sh_key_left.c
*/
void		sh_key_left(t_main *main);

/*
** sh_key_right.c
*/
void		sh_key_right(t_main *main);

/*
** sh_key_up.c
*/
void		sh_key_up(t_main *main);

/*
** sh_key_down.c
*/
void		sh_key_down(t_main *main);

/*
** sh_key_backspace.c
*/
void		sh_key_backspace(t_main *main);
void		sh_key_backspace_string(t_main *main);

/*
** sh_key_delete.c
*/
void		sh_key_delete(t_main *main);

/*
** sh_key_home.c
*/
void		sh_key_home(t_main *main);

/*
** sh_key_end.c
*/
void		sh_key_end(t_main *main);

/*
** sh_key_ctrl_d.c
*/
bool		sh_key_ctrl_d(t_main *main);

/*
** sh_key_shift_left.c
*/
void		sh_key_shift_left(t_main *main);

/*
** sh_key_shift_right.c
*/
void		sh_key_shift_right(t_main *main);
void		sh_key_shift_right_2(t_main *main);

/*
** sh_key_opt_c.c
*/
void		sh_key_opt_c(t_main *main);

/*
** sh_key_opt_v.c
*/
void		sh_key_opt_v(t_main *main);
uint64_t	sh_key_opt_v_select(t_main *main);
void		sh_key_opt_v_paste(t_main *main, uint64_t i, char *temp);

/*
** sh_key_opt_x.c
*/
void		sh_key_opt_x(t_main *main);
void		sh_key_opt_x_clean(t_main *main);
void		sh_key_opt_x_paste(t_main *main, char *temp);

/*
** sh_key_ctrl_left.c
*/
void		sh_key_ctrl_left(t_main *main);
void		sh_key_shift_left_2(t_main *main);

/*
** sh_key_ctrl_right.c
*/
void		sh_key_ctrl_right(t_main *main);

/*
** sh_key_opt_q.c
*/
void		sh_key_opt_q(t_main *main);

/*
** sh_key_opt_a.c
*/
void		sh_key_opt_a(t_main *main);

#endif
