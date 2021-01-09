/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_args_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:58 by eboris            #+#    #+#             */
/*   Updated: 2021/01/09 16:56:00 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_type_args_cmds(t_btype *new, char **argv, int i, t_main *main)
{
	if (argv[i] == NULL)
	{
		ft_fprintf(STDERR_FILENO, "42sh: type: no command name\n");
		return (false);
	}
	sh_type_args_cmds_write(new, argv, i, main);
	return (true);
	(void)new;
}

void	sh_type_args_cmds_write(t_btype *new, char **argv, int i, t_main *main)
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
	sh_type_args_fin_write(new, n, main);
	n = 0;
	while (argv[i] != NULL)
	{
		new->cmd[n] = sh_strdup(argv[i], main);
		i++;
		n++;
	}
	new->cmd[n] = NULL;
}

void	sh_type_args_fin_write(t_btype *new, int n, t_main *main)
{
	int	i;

	i = 0;
	new->fin = (char **)sh_memalloc(sizeof(char *) * (n + 1), main);
	while (i < n)
	{
		new->fin[i] = NULL;
		i++;
	}
}