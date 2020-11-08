/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:28:23 by eboris            #+#    #+#             */
/*   Updated: 2020/07/08 14:12:18 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_key_enter(t_main *main)
{
	ft_putstr_fd(tgetstr("do", NULL), main->fd);
	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	return (false);
}
