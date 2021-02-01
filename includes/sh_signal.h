/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:21:51 by eboris            #+#    #+#             */
/*   Updated: 2021/02/01 18:23:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SIGNAL_H
# define SH_SIGNAL_H

/*
** sh_signal.c
*/
void	sh_signal_set(void);
void	sh_signal_status(int status, pid_t pid);

/*
** sh_screen_resize.c
*/
void	sh_sig_screen_resize(int a);

/*
** sh_bus_error.c
*/
void	sh_sig_bus_error(int a);

/*
** sh_ctrl_c.c
*/
void	sh_sig_ctrl_c(int a);
void	sh_sig_ctrl_c_ks(t_main *g_main);
void	sh_new_prompt(t_main *g_main);

/*
** sh_ctrl_z.c
*/
void	sh_sig_ctrl_z(int a);

#endif
