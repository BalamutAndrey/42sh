/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo_spec_symb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:22:44 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 18:36:12 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_print_spec(char c)
{
	if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\\')
		ft_putchar('\\');
}

int		sh_is_octal_nbr(char c)
{
	if (c >= '0' && c <= '7')
		return (1);
	else
		return (0);
}

int		sh_check_octal_nbr(char *str, int i, t_main *main)
{
	int		j;
	int		nbr;
	char	*tmp;

	j = 0;
	if (!str[j] || sh_is_octal_nbr(str[j]) == 0)
		return (i + 2);
	while (sh_is_octal_nbr(str[j]) == 1 && j < 3)
		j++;
	tmp = sh_strsub(str, 0, j, main);
	nbr = ft_atoi_base(tmp, 8);
	ft_strdel(&tmp);
	ft_putchar(nbr);
	return (i + j + 2);
}

int		sh_echo_is_spec(char *str, int i, t_main *main)
{
	int		n;

	n = i + 1;
	if (str[n] == 'c')
		return (-1);
	if (str[n] == 'a' || str[n] == 'b' || str[n] == 'f' ||
		str[n] == 'n' || str[n] == 'r' || str[n] == 't' ||
		str[n] == 'v' || str[n] == '\\')
	{
		sh_print_spec(str[n]);
		return (i + 2);
	}
	else if (str[n] == '0')
		i = sh_check_octal_nbr(&str[n + 1], i, main);
	else
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
