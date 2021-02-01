/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:11:10 by geliz             #+#    #+#             */
/*   Updated: 2021/02/01 19:15:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** flags array flags[0] => -e flag ; flags[1] => -n flag
*/

int		sh_echo_get_flags(char **argv, int flags[2])
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-e") == 0)
		{
			flags[0] = 1;
			i++;
		}
		else if (ft_strcmp(argv[i], "-E") == 0)
		{
			flags[0] = 0;
			i++;
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
		{
			flags[1] = 1;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

int		sh_echo_with_changes(char **str, int j, int flags[2], t_main *main)
{
	int		i;

	i = 0;
	while (str[j][i])
	{
		if (str[j][i] != '\\')
		{
			ft_putchar(str[j][i]);
			i++;
		}
		else
		{
			i = sh_echo_is_spec(str[j], i, main);
			if (i == -1)
			{
				flags[1] = 1;
				return (-1);
			}
		}
	}
	return (j);
}

void	sh_builtin_echo(t_main *main, t_exec *exec)
{
	int		i;
	int		flags[2];

	flags[0] = 0;
	flags[1] = 0;
	i = sh_echo_get_flags(exec->argv, flags);
	while (exec->argv[i])
	{
		if (flags[0] == 0)
			ft_fprintf(STDOUT_FILENO, "%s", exec->argv[i]);
		if (flags[0] == 1)
		{
			i = sh_echo_with_changes(exec->argv, i, flags, main);
			if (i == -1)
				break ;
		}
		if (exec->argv[i + 1] && exec->argv[i][0] != '\0')
			ft_fprintf(STDOUT_FILENO, " ");
		i++;
	}
	if (flags[1] == 0)
		ft_fprintf(STDOUT_FILENO, "\n");
}
