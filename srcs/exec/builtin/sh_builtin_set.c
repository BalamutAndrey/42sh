/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:41:56 by geliz             #+#    #+#             */
/*   Updated: 2020/12/13 18:24:35 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_split_vars(t_vars *first, t_vars **a, t_vars **b)
{
	t_vars	*left;
	t_vars	*right;

	left = first;
	right = first->next;
	while (right)
	{
		right = right->next;
		if (right)
		{
			left = left->next;
			right = right->next;
		}
	}
	right = left->next;
	left->next = NULL;
	left = first;
	*a = left;
	*b = right;
}

t_vars	*sh_merge(t_vars *a, t_vars *b, int (*cmp)())
{
	t_vars	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (cmp(a, b) < 0)
	{
		result = a;
		result->next = sh_merge(a->next, b, (*cmp));
	}
	else
	{
		result = b;
		result->next = sh_merge(a, b->next, (*cmp));
	}
	return (result);
}

void	sh_sort_vars(t_vars **vars, int (*cmp)())
{
	t_vars	*first;
	t_vars	*a;
	t_vars	*b;

	first = *vars;
	if (first && first->next)
	{
		sh_split_vars(first, &a, &b);
		sh_sort_vars(&a, (*cmp));
		sh_sort_vars(&b, (*cmp));
		*vars = sh_merge(a, b, (*cmp));
	}
}

int		sh_alphabet_sort(t_vars *a, t_vars *b)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	return (res);
}

void	sh_builtin_set(t_main *main)
{
	t_vars	*tmp;

	sh_sort_vars(&main->vars, (*sh_alphabet_sort));
	tmp = main->vars;
	while (tmp)
	{
		ft_fprintf(STDOUT_FILENO, "%s%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
