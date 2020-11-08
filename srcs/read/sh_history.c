/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:49:25 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 12:27:51 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_history_add(t_main *main)
{
	if (main->ks[0] != '\0')
	{
		sh_history_newlist(main);
		main->hist_end->prev->com = sh_strnew(MAX_KS_LEN, main);
		ft_strncpy(main->hist_end->prev->com, main->ks, MAX_KS_LEN);
	}
}

void	sh_history_create(t_main *main)
{
	t_hist	*new;
	t_hist	*end;

	new = sh_memalloc(sizeof(t_hist), main);
	end = sh_memalloc(sizeof(t_hist), main);
	new->com = NULL;
	end->com = NULL;
	new->next = end;
	new->prev = NULL;
	end->next = NULL;
	end->prev = new;
	main->hist = new;
	main->hist_curr = end;
	main->hist_end = end;
}

void	sh_history_newlist(t_main *main)
{
	t_hist	*new;
	t_hist	*temp;

	temp = main->hist_end->prev;
	new = sh_memalloc(sizeof(t_hist), main);
	new->com = NULL;
	new->next = main->hist_end;
	new->prev = temp;
	temp->next = new;
	main->hist_end->prev = new;
	main->hist_curr = main->hist_end;
}
