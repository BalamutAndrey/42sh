/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_envvar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:48:13 by eboris            #+#    #+#             */
/*   Updated: 2020/11/02 16:49:20 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_envvar(t_envvar *envvar)
{
	t_envvar	*temp;

	if (envvar != NULL)
	{
		temp = envvar;
		while (temp != NULL)
		{
			envvar = temp->next;
			temp->str = NULL;
			temp->next = NULL;
			free(temp);
			temp = envvar;
		}
	}
}
