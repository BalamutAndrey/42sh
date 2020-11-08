/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:36:22 by eboris            #+#    #+#             */
/*   Updated: 2020/07/08 15:43:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_delete(t_main *main)
{
	uint64_t	i;
	char		*temp;

	if (main->cursor < main->ks_len)
	{
		i = main->cursor;
		temp = ft_strnew(MAX_KS_LEN);
		while (main->ks[i] != '\0')
		{
			temp[i - main->cursor] = main->ks[i];
			i++;
		}
		i = 1;
		while (temp[i] != '\0')
		{
			main->ks[main->cursor + i - 1] = temp[i];
			i++;
		}
		main->ks[main->cursor + i - 1] = '\0';
		ft_strdel(&temp);
		main->ks_len--;
		sh_reprint_ks(main);
	}
}
