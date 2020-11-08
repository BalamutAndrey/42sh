/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:21:51 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 13:06:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SIGNAL_H
# define SH_SIGNAL_H

/*
** sh_signal.c
*/
void	sh_signal_set(void);

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

#endif
