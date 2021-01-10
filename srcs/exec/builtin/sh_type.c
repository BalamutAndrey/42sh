/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:34:04 by eboris            #+#    #+#             */
/*   Updated: 2021/01/10 15:25:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_type(t_exec *exec, t_main *main)
{
	t_btype	*new;
	int		i;

	new = sh_type_create_struct(main);
	i = 0;
	if (sh_type_read_args(exec, new, main) == true)
	{
		if (!new->f && !new->p && !new->t && !new->big_p)
		{
			new->f = true;
			new->p = true;
		}
		sh_type_check_cmd(main, new);
		while (new->cmd[i] != NULL)
		{
			if (new->fin[i] != NULL)
				ft_printf("%s\n", new->fin[i]);
			i++;
		}
	}
	else
		sh_type_args_usage();
	sh_type_remove_struct(&new);
}

t_btype	*sh_type_create_struct(t_main *main)
{
	t_btype	*new;

	new = (t_btype*)sh_memalloc(sizeof(t_btype), main);
	new->a = false;
	new->f = false;
	new->p = false;
	new->t = false;
	new->big_p = false;
	new->cmd = NULL;
	new->fin = NULL;
	return (new);
}

void	sh_type_remove_struct(t_btype **new)
{
	int		i;
	t_btype	*temp;

	i = 0;
	temp = *new;
	if (temp->cmd != NULL)
	{
		while (temp->cmd[i] != NULL)
		{
			ft_strdel(&temp->cmd[i]);
			if (temp->fin[i] != NULL)
				ft_strdel(&temp->fin[i]);
			i++;
		}
		free(temp->cmd);
		free(temp->fin);
		temp->cmd = NULL;
		temp->fin = NULL;
	}
	free(temp);
	temp = NULL;
	*new = NULL;
}

void	sh_type_check_cmd(t_main *main, t_btype *new)
{
	int i;

	i = 0;
	while (new->cmd[i] != NULL)
	{
		if (new->a == true)
			sh_type_check_a(main, new, i);
		else
		{
			if (new->f == true)
				sh_type_check_f(main, new, i);
			if (new->p == true)
				sh_type_check_p(main, new, i);
			if (new->t == true)
				sh_type_check_t(main, new, i);
			if (new->big_p == true)
				sh_type_check_bigp(main, new, i);
		}
		if (new->fin[i] != NULL)
			new->fin[i][ft_strlen(new->fin[i]) - 1] = '\0';
		i++;
	}
}
