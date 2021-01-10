/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_check_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:32:25 by eboris            #+#    #+#             */
/*   Updated: 2021/01/10 15:25:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_type_check_f(t_main *main, t_btype *new, int i)
{
	if (sh_is_builtin(new->cmd[i]) == true)
	{
		new->fin[i] = sh_strjoin_arg(main, "%f %s %s %s",
			new->fin[i], new->cmd[i], " ", "is a shell builtin\n");
	}
}

void	sh_type_check_p(t_main *main, t_btype *new, int i)
{
	t_exec	*temp;

	temp = sh_memalloc(sizeof(t_exec), main);
	temp->argv = sh_memalloc(sizeof(char*), main);
	temp->argv[0] = sh_strdup(new->cmd[i], main);
	sh_find_path(main, temp);
	if (sh_run_access(&temp->argv[0]) == 0)
	{
		new->fin[i] = sh_strjoin_arg(main, "%f %s %s %s %f %s",
			new->fin[i], new->cmd[i], " ", "is ", temp->argv[0], "\n");
	}
	free(temp->argv);
	free(temp);
}

void	sh_type_check_t(t_main *main, t_btype *new, int i)
{
	if (sh_is_builtin(new->cmd[i]) == true)
	{
		new->fin[i] = sh_strjoin_arg(main, "%f %s",
			new->fin[i], "builtin\n");
	}
}

void	sh_type_check_bigp(t_main *main, t_btype *new, int i)
{
	t_exec	*temp;

	temp = sh_memalloc(sizeof(t_exec), main);
	temp->argv = sh_memalloc(sizeof(char*), main);
	temp->argv[0] = sh_strdup(new->cmd[i], main);
	sh_find_path(main, temp);
	if (sh_run_access(&temp->argv[0]) == 0)
	{
		new->fin[i] = sh_strjoin_arg(main, "%f %f %s",
			new->fin[i], temp->argv[0], "\n");
	}
	free(temp->argv);
	free(temp);
}

void	sh_type_check_a(t_main *main, t_btype *new, int i)
{
	if (new->t)
		sh_type_check_t(main, new, i);
	else
		sh_type_check_f(main, new, i);
	if (new->big_p)
		sh_type_check_bigp(main, new, i);
	else
		sh_type_check_p(main, new, i);
}
