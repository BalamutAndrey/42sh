/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:27:09 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 12:45:39 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_signal_set(void)
{
	signal(SIGWINCH, sh_sig_screen_resize);
	signal(SIGINT, sh_sig_ctrl_c);
}
