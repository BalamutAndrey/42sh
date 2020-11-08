/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:43:26 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 17:37:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_slash(t_main *main)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(main->ks);
	while (j > 0 && main->ks[j - 1] == '\\')
	{
		j--;
		i++;
	}
	if (i % 2 != 0)
		main->prompt = sh_strdup("slash", main);
}
