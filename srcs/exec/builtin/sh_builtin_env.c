/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:35:02 by geliz             #+#    #+#             */
/*   Updated: 2020/11/08 14:50:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_env(t_main *main)
{
	int		i;
	char	**env;

	i = 0;
	if (main->envp_curr)
		env = main->envp_curr;
	else
		return ;
	while (env[i])
	{
		ft_fprintf(STDOUT_FILENO, "%s\n", env[i]);
		i++;
	}
}
