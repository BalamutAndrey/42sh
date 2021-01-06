/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:43:26 by geliz             #+#    #+#             */
/*   Updated: 2021/01/06 14:20:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_slash(t_main *main)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = main->ks;
	j = ft_strlen(str);
	while (j > 0 && str[j - 1] == '\\')
	{
		j--;
		i++;
	}
	if (i % 2 != 0)
		main->prompt = sh_strdup("slash", main);
}
