/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_alias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:15:43 by geliz             #+#    #+#             */
/*   Updated: 2021/01/08 14:18:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_alias(t_main *temp)
{
	t_alias	*al;
	t_alias	*nxt;

	al = temp->alias;
	while (al)
	{
		ft_strdel(&al->name);
		ft_strdel(&al->command);
		nxt = al->next;
		al->next = NULL;
		free(al);
		al = nxt;
	}
	al = NULL;
	nxt = NULL;
	temp->alias = NULL;
}
