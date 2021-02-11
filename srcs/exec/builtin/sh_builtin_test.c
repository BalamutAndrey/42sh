/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:24:48 by geliz             #+#    #+#             */
/*   Updated: 2021/02/10 01:25:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

//  ,  1,  2,  3,  4,  5,  6,  7,  8, 9,  10, 11, 12, 13, 14, 15, 16, 17,  18,  19,  20,  21,  22
// !, -b, -c, -d, -e, -f, -g, -L, -p, -r, -S, -s, -u, -w, -x, -z,  =, !=, -eq, -ne, -ge, -lt, -le

int		sh_builtin_test_more_un_op(char c)
{
	if (c == 'p')
		return (8);
	else if (c == 'r')
		return (9);
	else if (c == 'S')
		return (10);
	else if (c == 's')
		return (11);
	else if (c == 'u')
		return (12);
	else if (c == 'w')
		return (13);
	else if (c == 'x')
		return (14);
	else if (c == 'z')
		return (15);
	else
		return (0);
}

int		sh_bultin_test_un_op(char **av)
{
	char	c;

	if (ft_strlen(av[1]) == 2 && av[1][0] == '-')
	{
		c = av[1][1];
		if (c == 'b')
			return (1);
		else if (c == 'c')
			return (2);
		else if (c == 'd')
			return (3);
		else if (c == 'e')
			return (4);
		else if (c == 'f')
			return (5);
		else if (c == 'g')
			return (6);
		else if (c == 'L')
			return (7);
		else
			return (sh_builtin_test_more_un_op(c));
	}
	return (0);
}

int		sh_builtin_test_bin_op(char **av)
{
	if (ft_strcmp(av[2], "!") == 0)
		return (16);
	else if (ft_strcmp(av[2], "!=") == 0)
		return (17);
	else if (ft_strcmp(av[2], "-eq") == 0)
		return (18);
	else if (ft_strcmp(av[2], "-ne") == 0)
		return (19);
	else if (ft_strcmp(av[2], "-ge") == 0)
		return (20);
	else if (ft_strcmp(av[2], "-lt") == 0)
		return (21);
	else if (ft_strcmp(av[2], "-le") == 0)
		return (22);
	else
		return (0);
}

int		sh_builtin_test_opt_check(t_exec *exec)
{
	int		ret;
	int		count;

	ret = 0;
	count = 0;
	while (exec->argv[count])
		count++;
	if (count > 4)
		return (-1);
	else if (count == 4)
		ret = sh_builtin_test_bin_op(exec->argv);
	else if (count == 3)
		ret = sh_builtin_test_un_op(exec->argv);
	return (ret);
}

char	*sh_builtin_test(t_main *main, t_exec *exec)
{
	int		type;

	if (exec->argv[1] && ft_strcmp(exec->argv[1], "!") == 0 && !exec->argv[2])
	{
		exec->exit_s = 0;
		return (NULL);
	}
	if (!exec->argv[1] || !exec->argv[2])
		return (NULL);
	if ((type = sh_builtin_test_opt_check(exec)) == 0)
		return (NULL);
	if (type == -1)
		return (sh_strdup("42sh: test: too many arguments\n", main));
	if (type > 0 && type < 16)
		sh_builtin_test_file(type, exec);
	else
		sh_builtin_test_compare(type, exec);
	return (NULL);
}
