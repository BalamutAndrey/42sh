/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_envp_curr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:53:54 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 15:24:20 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_envp_curr(t_main *main)
{
	int i;

	i = 0;
	if (main->envp_curr != NULL)
	{
		while (main->envp_curr[i] != NULL)
		{
			ft_strdel(&main->envp_curr[i]);
			i++;
		}
		free(main->envp_curr);
		main->envp_curr = NULL;
	}
}
