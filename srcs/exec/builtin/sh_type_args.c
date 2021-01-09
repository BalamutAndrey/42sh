/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:49:11 by eboris            #+#    #+#             */
/*   Updated: 2021/01/09 16:32:01 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_type_read_args(t_exec *exec, t_btype *new, t_main *main)
{
	int	i;

	i = 1;
	while ((exec->argv[i] != NULL) && (exec->argv[i][0] == '-'))
	{
		if (sh_type_args_keys(new, exec->argv[i]) == true)
			i++;
		else
			return (false);
	}
	if (sh_type_args_cmds(new, exec->argv, i, main) == false)
		return (false);
	return (true);
}

void	sh_type_args_usage(void)
{
	ft_fprintf(STDERR_FILENO, "usage: type [-afptP] name [name ...]\n");
}
