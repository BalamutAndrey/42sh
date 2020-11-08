/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:35:00 by eboris            #+#    #+#             */
/*   Updated: 2020/10/31 19:14:08 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_fds(t_main *main)
{
	t_fds	*temp;

	if (main->opfds != NULL)
	{
		temp = main->opfds;
		while (temp != NULL)
		{
			main->opfds = temp->next;
			free(temp);
			temp = main->opfds;
		}
		main->opfds = NULL;
	}
}
