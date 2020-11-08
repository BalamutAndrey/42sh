/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:27:56 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 16:47:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen_ll_itoa(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i += 2;
		n = n / 10 * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_convert_ll_nbr(char *str, long long int n, size_t i)
{
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		str[i] = n % 10 * -1 + '0';
		n = n / 10 * -1;
		i--;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_ll_itoa(long long int n)
{
	char	*str;
	int		i;

	i = ft_intlen_ll_itoa(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = ft_convert_ll_nbr(str, n, (i - 1));
	return (str);
}
