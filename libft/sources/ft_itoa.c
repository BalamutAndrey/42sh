/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:02:30 by geliz             #+#    #+#             */
/*   Updated: 2019/09/27 14:33:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;
	long	z;

	i = 0;
	z = n;
	if (z < 0)
	{
		i++;
		z = z * -1;
	}
	if (z == 0)
		i = 1;
	while (z > 0)
	{
		z = z / 10;
		i++;
	}
	return (i);
}

static char		*ft_convert(char *str, int n, size_t i)
{
	long	z;

	z = n;
	if (z < 0)
	{
		z = z * -1;
		str[0] = '-';
	}
	if (z == 0)
		str[0] = '0';
	while (z > 0)
	{
		str[i] = z % 10 + '0';
		z = z / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = ft_intlen(n);
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, n, (i - 1));
	return (str);
}
