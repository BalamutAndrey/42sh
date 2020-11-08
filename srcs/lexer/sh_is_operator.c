/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_is_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:27:49 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 15:23:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_is_operator(char *str)
{
	if (!ft_strncmp(str, "<<-", 3))
		return (3);
	if (!ft_strncmp(str, "&&", 2) || !ft_strncmp(str, "||", 2)
		|| !ft_strncmp(str, ";;", 2) || !ft_strncmp(str, "<<", 2)
		|| !ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<&", 2)
		|| !ft_strncmp(str, ">&", 2) || !ft_strncmp(str, "<>", 2)
		|| !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '|' || *str == ';' || *str == '>' || *str == '<' ||
			*str == '&' || *str == '(' || *str == ')')
		return (1);
	else
		return (0);
}

int		sh_is_it_io_redirect_operator(char *str)
{
	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, "<&", 2)
		|| !ft_strncmp(str, ">&", 2) || !ft_strncmp(str, "<>", 2)
		|| !ft_strncmp(str, ">|", 2))
		return (2);
	else if (*str == '>' || *str == '<')
		return (1);
	else
		return (0);
}
