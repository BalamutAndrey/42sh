/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_type_args_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:25:44 by eboris            #+#    #+#             */
/*   Updated: 2021/01/10 13:44:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_type_args_keys(t_btype *new, char *str)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(str);
	if (len > 1)
	{
		while (i < len)
		{
			if (sh_type_args_key_check(new, str[i]) == true)
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

bool	sh_type_args_key_check(t_btype *new, char c)
{
	if (c == 'a')
	{
		new->a = true;
	}
	else if (c == 'f')
	{
		new->t = false;
		new->f = true;
	}
	else if (c == 'p')
	{
		new->p = true;
		new->big_p = false;
	}
	else
	{
		return (sh_type_args_key_check_other(new, c));
	}
	return (true);
}

bool	sh_type_args_key_check_other(t_btype *new, char c)
{
	if (c == 't')
	{
		new->t = true;
		new->f = false;
	}
	else if (c == 'P')
	{
		new->big_p = true;
		new->p = false;
	}
	else
		return (false);
	return (true);
}
