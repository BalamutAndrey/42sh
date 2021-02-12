/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:49:12 by eboris            #+#    #+#             */
/*   Updated: 2021/02/12 20:36:38 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_exit(t_exec *exec, t_main *main)
{
	int		code;

	if (exec && exec->argv[1])
	{
		if (exec->argv[2])
		{
			exec->exit_s = 1;
			return (sh_strdup(
				"42sh: exit: error: too many arguments\n", main));
		}
		if (sh_exit_check_number(exec->argv[1]) == false)
		{
			exec->exit_s = 1;
			return (sh_strdup(
				"42sh: exit: error: a numerical value is expected\n", main));
		}
		code = ft_atoi(exec->argv[1]);
	}
	else
		code = 0;
	sh_term_restore(main);
	sh_remove_struct(&main);
	exit(code);
}

void	sh_exit_error(t_main *main)
{
	sh_term_restore(main);
	sh_remove_struct(&main);
	exit(1);
}

bool	sh_exit_check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
		i++;
	}
	return (true);
}
