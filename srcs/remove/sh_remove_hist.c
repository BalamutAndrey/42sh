/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_hist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:59:21 by eboris            #+#    #+#             */
/*   Updated: 2020/10/31 19:14:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_hist(t_main *main)
{
	t_hist	*temp;

	if (main->hist != NULL)
	{
		temp = main->hist;
		while (temp != NULL)
		{
			main->hist = temp->next;
			if (temp->com != NULL)
				ft_strdel(&temp->com);
			free(temp);
			temp = main->hist;
		}
		main->hist = NULL;
		main->hist_curr = NULL;
		main->hist_end = NULL;
	}
}
