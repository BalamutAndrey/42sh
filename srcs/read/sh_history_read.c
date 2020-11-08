/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_history_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:33:11 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 12:29:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_history_read(t_main *main, char k)
{
	if ((main->ks[0] != '\0') && (main->hist_curr == main->hist_end))
	{
		main->hist_end->com = sh_strnew(MAX_KS_LEN, main);
		ft_strncpy(main->hist_end->com, main->ks, MAX_KS_LEN);
		ft_bzero(main->ks, MAX_KS_LEN);
	}
	if (main->hist != NULL)
	{
		if ((k == 'u') && (main->hist_curr->prev != NULL) &&
			(main->hist_curr->prev != main->hist))
		{
			main->hist_curr = main->hist_curr->prev;
			sh_history_read_up(main);
		}
		else if (k == 'd')
		{
			sh_history_read_down(main);
		}
	}
}

void	sh_history_read_up(t_main *main)
{
	ft_bzero(main->ks, MAX_KS_LEN);
	ft_strncpy(main->ks, main->hist_curr->com, MAX_KS_LEN);
	main->ks_len = ft_strlen(main->ks);
	main->cursor = main->ks_len;
	sh_reprint_ks(main);
}

void	sh_history_read_down(t_main *main)
{
	if (main->hist_curr->next != NULL)
	{
		main->hist_curr = main->hist_curr->next;
	}
	if (main->hist_curr->com != NULL)
	{
		ft_bzero(main->ks, MAX_KS_LEN);
		ft_strncpy(main->ks, main->hist_curr->com, MAX_KS_LEN);
		main->ks_len = ft_strlen(main->ks);
		main->cursor = main->ks_len;
		sh_reprint_ks(main);
	}
	else
	{
		ft_bzero(main->ks, MAX_KS_LEN);
		main->ks_len = 0;
		main->cursor = 0;
		sh_reprint_ks(main);
	}
}
