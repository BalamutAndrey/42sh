/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_ll_itoa_base_hub.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:36:59 by geliz             #+#    #+#             */
/*   Updated: 2020/01/17 21:43:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_ll_itoa_base(unsigned long long int n, int base)
{
	char	*str;
	int		i;

	if (base != 'x' && base != 'X' && base != 'o' && base != 'd' && base != 'b')
		return (NULL);
	i = ft_intlen_base(n, base);
	if (base == 'd')
		str = ft_convert_deci(n, i);
	if (base == 'o')
		str = ft_convert_octal(n, i);
	if (base == 'x' || base == 'X')
		str = ft_convert_hexadec(n, i);
	if (base == 'b')
		str = ft_convert_binary(n, i);
	i = 0;
	if (base == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}
