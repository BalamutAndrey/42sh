/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:21:40 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:25:00 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_ctrl_right(t_main *main)
{
	int	i;

	i = main->cursor + 1;
	while (main->ks[i] != '\0' && ((main->ks[i] != ' ') &&
		(main->ks[i] != '\n')))
	{
		i++;
		sh_cursor_plus(main);
	}
	sh_cursor_plus(main);
	sh_cursor_plus(main);
}
