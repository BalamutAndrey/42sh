/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_ll_itoa_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:27:56 by geliz             #+#    #+#             */
/*   Updated: 2020/01/17 21:43:38 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_binary(unsigned long long int n, int i)
{
	char	*str;

	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	while (n > 0)
	{
		str[i] = n % 2 + '0';
		n = n / 2;
		i--;
	}
	return (str);
}

char	*ft_convert_hexadec(unsigned long long int n, int i)
{
	char	*str;

	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = n % 16 + '0';
		if (str[i] > '9')
			str[i] = str[i] + 39;
		n = n / 16;
		i--;
	}
	return (str);
}

char	*ft_convert_octal(unsigned long long int n, int i)
{
	char	*str;

	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = n % 8 + '0';
		n = n / 8;
		i--;
	}
	return (str);
}

char	*ft_convert_deci(unsigned long long int n, int i)
{
	char	*str;

	if (!(str = ft_strnew(i)))
		return (NULL);
	i--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

int		ft_intlen_base(unsigned long long int n, int base)
{
	int		i;
	int		z;

	if (base == 'o')
		z = 8;
	if (base == 'x' || base == 'X')
		z = 16;
	if (base == 'd')
		z = 10;
	if (base == 'b')
		z = 2;
	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / z;
		i++;
	}
	return (i);
}
