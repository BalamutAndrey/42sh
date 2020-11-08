/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_prec_zero.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:30:46 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:26:00 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision_zero_round_up(char *nbr, int i, int pos)
{
	int		ost;
	int		n;

	ost = 0;
	if (nbr[i] > '4')
	{
		ost = 1;
		i--;
		while (--i >= pos)
		{
			n = (nbr[i] - '0') + ost;
			nbr[i] = n % 10 + '0';
			ost = n / 10 > 0 ? 1 : 0;
		}
	}
	return (ost);
}

char	*ft_precision_float_zero(char *nbr, int i, t_info *in)
{
	char	*ret;
	int		ost;
	int		pos;

	pos = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		pos = 1;
	ost = ft_precision_zero_round_up(nbr, i, pos);
	if (!(ret = ft_strnew(i - 1 + in->octotorp + ost)))
		return (NULL);
	i = 0;
	if (pos == 1)
		ret[i] = nbr[i];
	i = i + pos;
	if (ost == 1)
		ret[i++] = '1';
	while (nbr[i - ost] != '.')
	{
		ret[i] = nbr[i - ost];
		i++;
	}
	if (in->octotorp == 1)
		ret[i] = '.';
	return (ret);
}
