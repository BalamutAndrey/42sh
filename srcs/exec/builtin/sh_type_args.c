/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:49:11 by eboris            #+#    #+#             */
/*   Updated: 2021/01/09 14:51:19 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_type_read_args(t_exec *exec, t_btype *new, t_main *main)
{
	int	i;

	i = 1;
	while ((exec->argv[i] != NULL) && (exec->argv[i][0] == '-'))
	{
		if (sh_type_arg_keys(new, exec->argv[i]) == true)
			i++;
		else
			return (false);
	}
	if (sh_type_arg_cmds(new, exec->argv, i, main) == false)
		return (false);
	return (true);
}

bool	sh_type_arg_keys(t_btype *new, char *str)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(str);
	if (len > 1)
	{
		while (i < len)
		{
			if (sh_type_arg_key_check(new, str[i]) == true)
				i++;
			else
			{
				ft_fprintf(STDERR_FILENO,
					"42sh: type: bad option: -%c\n", str[i]);
				return (false);
			}
		}
	}
	else
	{
		ft_fprintf(STDERR_FILENO, "42sh: type: bad option: -\n");
		return (false);
	}
	return (true);
}

bool	sh_type_arg_key_check(t_btype *new, char c)
{
	if (c == 'a')
	{
		new->a = true;
	}
	else if (c == 'f')
	{
		new->f = true;
	}
	else if (c == 'p')
	{
		new->p = true;
		new->f = false;
	}
	else if (c == 't')
	{
		new->t = true;
	}
	else if (c == 'P')
	{
		new->big_p = true;
		new->a = false;
	}
	else
		return (false);
	return (true);
}

bool	sh_type_arg_cmds(t_btype *new, char **argv, int i, t_main *main)
{
	if (argv[i] == NULL)
	{
		ft_fprintf(STDERR_FILENO, "42sh: type: no command name\n");
		return (false);
	}
	sh_type_arg_cmds_write(new, argv, i, main);
	return (true);
	(void)new;
}

void	sh_type_arg_cmds_write(t_btype *new, char **argv, int i, t_main *main)
{
	int	n;
	int	temp;

	temp = i;
	n = 0;
	while (argv[temp] != NULL)
	{
		temp++;
		n++;
	}
	new->cmd = (char **)sh_memalloc(sizeof(char *) * (n + 1), main);
	n = 0;
	while (argv[i] != NULL)
	{
		new->cmd[n] = sh_strdup(argv[i], main);
		i++;
		n++;
	}
	new->cmd[n] = NULL;
}
