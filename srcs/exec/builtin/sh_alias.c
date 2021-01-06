/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:55:10 by eboris            #+#    #+#             */
/*   Updated: 2021/01/06 18:13:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_alias(t_exec *exec, t_main *main)
{
	char	*fin;

	fin = NULL;
	if (!exec->argv[1])
	{
		sh_alias_print(main);
		return (fin);
	}
	fin = sh_alias_arg(exec, main);
	return (fin);
}
