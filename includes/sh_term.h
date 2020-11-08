/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:37:59 by eboris            #+#    #+#             */
/*   Updated: 2020/07/06 15:33:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TERM_H
# define SH_TERM_H

/*
** sh_term_check_errors_start.c
*/
bool	sh_term_check_errors_start(int argc, char **argv, char **env);

/*
** sh_term_init.c
*/
bool	sh_term_init(t_main *main);
void	sh_ioctl(t_main *main);
void	sh_term_restore(t_main *main);

#endif
