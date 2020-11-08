/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:09:16 by eboris            #+#    #+#             */
/*   Updated: 2020/07/17 18:21:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_c(t_main *main)
{
	uint64_t	i;
	uint64_t	n;

	n = 0;
	ft_bzero(main->cursor_sel_text, MAX_KS_LEN);
	if (main->cursor_sel == true)
	{
		i = main->cursor_sel_start;
		while (i <= main->cursor_sel_end)
		{
			main->cursor_sel_text[n] = main->ks[i];
			i++;
			n++;
		}
	}
}
