/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:55:27 by eboris            #+#    #+#             */
/*   Updated: 2020/06/28 12:02:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ERRORS_H
# define SH_ERRORS_H

/*
** errors/sh_term_errors.c
*/
void	sh_term_errors_start(uint8_t error);
void	sh_error_init(uint8_t error, t_main *main);

#endif
