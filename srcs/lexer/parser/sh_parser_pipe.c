/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:36:28 by geliz             #+#    #+#             */
/*   Updated: 2020/12/19 12:41:46 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_pipe(t_main *main)
{
	int		j;

	j = ft_strlen(main->ks) - 1;
	if (j > 0 && main->ks[j] == '|' &&
		main->ks[j - 1] != '\\' && main->ks[j - 1] != '|')
	{
		main->prompt = sh_strdup("pipe", main);
	}
}
