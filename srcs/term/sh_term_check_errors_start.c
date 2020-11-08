/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_check_errors_start.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:14:42 by eboris            #+#    #+#             */
/*   Updated: 2020/07/08 14:10:58 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_term_check_errors_start(int argc, char **argv, char **env)
{
	if (*env == NULL || env == NULL)
	{
		sh_term_errors_start(1);
		return (true);
	}
	if (!isatty(0))
	{
		sh_term_errors_start(2);
		return (true);
	}
	(void)argc;
	(void)argv;
	return (false);
}
