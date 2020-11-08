/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:12:07 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 18:36:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_x_clean(t_main *main)
{
	uint64_t	i;
	uint64_t	n;

	i = main->cursor_sel_start;
	n = 0;
	while (i <= main->cursor_sel_end)
	{
		main->cursor_sel_text[n] = main->ks[i];
		main->ks[i] = '\0';
		i++;
		n++;
	}
}

void	sh_key_opt_x_paste(t_main *main, char *temp)
{
	uint64_t	i;
	uint64_t	n;

	i = main->cursor_sel_start;
	n = 0;
	while (temp[n] != '\0')
	{
		main->ks[i] = temp[n];
		i++;
		n++;
	}
}

void	sh_key_opt_x(t_main *main)
{
	uint64_t	i;
	uint64_t	n;
	char		*temp;

	ft_bzero(main->cursor_sel_text, MAX_KS_LEN);
	if (main->cursor_sel == true)
	{
		temp = sh_strnew(MAX_KS_LEN, main);
		i = main->cursor_sel_end + 1;
		n = 0;
		while (main->ks[i] != '\0')
		{
			temp[n] = main->ks[i];
			main->ks[i] = '\0';
			i++;
			n++;
		}
		sh_key_opt_x_clean(main);
		sh_key_opt_x_paste(main, temp);
		main->ks_len = ft_strlen(main->ks);
		ft_strdel(&temp);
		main->cursor_sel = false;
		main->cursor = main->cursor_sel_start;
		sh_reprint_ks(main);
	}
}
