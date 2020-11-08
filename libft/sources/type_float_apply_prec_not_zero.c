/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_prec_not_zero.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:31:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 16:38:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision_round_up_integ_part_ost(char *nbr, int len, int pos)
{
	int		ost;
	int		n;

	ost = 1;
	while (--len >= pos && ost == 1)
	{
		n = (nbr[len] - '0') + ost;
		nbr[len] = n % 10 + '0';
		ost = n / 10 > 0 ? 1 : 0;
	}
	return (ost);
}

char	*ft_precision_round_up_integ_part(char *nbr, int len, int prec)
{
	char	*ret;
	int		i;
	int		pos;
	int		ost;

	pos = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		pos = 1;
	ost = ft_precision_round_up_integ_part_ost(nbr, (len - 1), pos);
	if (!(ret = ft_strnew(len + prec + ost)))
		return (NULL);
	i = 0;
	if (pos == 1)
		ret[i] = nbr[i];
	i = i + pos;
	if (ost == 1)
		ret[i++] = '1';
	while (i < (len + prec + ost))
	{
		ret[i] = nbr[i - ost];
		i++;
	}
	return (ret);
}

char	*ft_precision_less_cut_str(char *nbr, int len, int prec)
{
	char	*ret;
	int		i;
	int		n;
	int		ost;

	i = prec;
	ost = nbr[len + prec] > '4' ? 1 : 0;
	while (ost == 1 && --i >= 0)
	{
		n = (nbr[len + i] - '0') + ost;
		nbr[len + i] = n % 10 + '0';
		ost = n / 10 > 0 ? 1 : 0;
	}
	if (ost == 1)
		ret = ft_precision_round_up_integ_part(nbr, len, prec);
	else
	{
		if (!(ret = ft_strnew(len + prec)))
			return (NULL);
		i = -1;
		while (++i < len + prec)
			ret[i] = nbr[i];
	}
	ft_strdel(&nbr);
	return (ret);
}

char	*ft_precision_more_add_zero(char *nbr, int len, int af_dot, int prec)
{
	char	*ret;
	int		dif;
	int		j;

	dif = prec - af_dot;
	j = 0;
	if (!(ret = ft_strnew(len + prec)))
		return (NULL);
	while (nbr[j] != '\0')
	{
		ret[j] = nbr[j];
		j++;
	}
	while (dif-- > 0)
		ret[j++] = '0';
	ft_strdel(&nbr);
	return (ret);
}
