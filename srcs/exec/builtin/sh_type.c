/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:34:04 by eboris            #+#    #+#             */
/*   Updated: 2021/01/09 16:57:31 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_type(t_exec *exec, t_main *main)
{
	t_btype	*new;

	new = sh_type_create_struct(main);
	if (sh_type_read_args(exec, new, main) == true)
	{
		// FOR TEST ONLY
		ft_printf("a = %i\n", new->a);
		ft_printf("f = %i\n", new->f);
		ft_printf("p = %i\n", new->p);
		ft_printf("t = %i\n", new->t);
		ft_printf("P = %i\n --- \n", new->big_p);
		int i = 0;
		while (new->cmd[i] != NULL)
		{
			ft_printf("cmd[%i] = %s\t\t\tfin[%i] = %s\n", i, new->cmd[i], i, new->fin[i]);
			i++;
		}
		// END FOR TEST ONLY
	}
	else
	{
		sh_type_args_usage();
	}
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
