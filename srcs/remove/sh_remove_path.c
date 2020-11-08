/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:05:12 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 14:45:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_path(t_main *main)
{
	t_path	*temp;

	if (main->path != NULL)
	{
		temp = main->path;
		while (temp != NULL)
		{
			main->path = temp->next;
			if (temp->path != NULL)
				ft_strdel(&temp->path);
			free(temp);
			temp = main->path;
		}
		main->path = NULL;
	}
}
