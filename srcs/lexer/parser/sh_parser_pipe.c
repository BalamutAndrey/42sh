/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:36:28 by geliz             #+#    #+#             */
/*   Updated: 2021/01/06 14:21:23 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_pipe(t_main *main)
{
	int		j;
	char	*str;

	str = main->ks;
	j = ft_strlen(str) - 1;
	if (j > 0 && str[j] == '|' && str[j - 1] != '|' &&
		(sh_is_protected(str, j) == 0))
	{
		main->prompt = sh_strdup("pipe", main);
	}
}
