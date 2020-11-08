/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_lib_atoi_toupp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:42:04 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 16:30:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_spaces(const char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') ||
		(str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') && (str[i + 1] >= '0') && (str[i + 1] <= '9'))
		i++;
	res = &((char *)str)[i];
	return (res);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	long	res;
	int		sign;
	char	*nstr;

	i = 0;
	res = 0;
	sign = 1;
	nstr = ft_spaces(str);
	if (nstr[i] == '-' && nstr[i + 1] >= '0' && nstr[i + 1] <= '9')
	{
		sign = -1;
		i++;
	}
	while (nstr[i] >= '0' && nstr[i] <= '9')
	{
		if ((res * 10 + (nstr[i] - '0')) / 10 != res)
			return (sign == -1 ? 0 : -1);
		res = res * 10 + (nstr[i] - '0');
		i++;
	}
	return ((int)res * sign);
}

int			ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = c - 32;
	return (c);
}
