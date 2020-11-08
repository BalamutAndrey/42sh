/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:49:38 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 19:11:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_zero_and_hidden_to_mant(char *temp, int exp)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 1;
	ret = ft_strnew(53);
	ret[0] = exp == -1023 ? '0' : '1';
	i = ft_strlen(temp);
	if (i < 52)
	{
		i = 52 - i;
		while (i-- > 0)
			ret[j++] = '0';
	}
	i = 0;
	while (temp[i] != '\0')
		ret[j++] = temp[i++];
	ft_strdel(&temp);
	return (ret);
}

int		ft_count_square(char c, int j)
{
	int		ret;

	ret = 1;
	if (c == '1')
	{
		while (j > 0)
		{
			ret = ret * 2;
			j--;
		}
		return (ret);
	}
	return (0);
}

int		ft_binary_str_to_int(char *temp)
{
	int		i;
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	i = (int)ft_strlen(temp) - 1;
	while (i > -1)
	{
		ret = ret + ft_count_square(temp[i], j);
		i--;
		j++;
	}
	ft_strdel(&temp);
	return (ret);
}

char	*ft_check_nan_and_inf(t_info *in, t_float d)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	if (d.t_bit.exponent == 2047)
	{
		if (d.t_bit.mantissa == 0 && d.d == d.d)
			return (ret = ft_keys_to_inf(in, ret, d.t_bit.sign));
		else
		{
			if (!(temp = ft_strsub("nan", 0, 3)))
				return (NULL);
			if (in->width > 3)
			{
				ret = ft_width_to_inf_or_nan(in, temp);
				ft_strdel(&temp);
				return (ret);
			}
			return (temp);
		}
	}
	return (NULL);
}

char	*ft_apply_info_to_flt(t_info *in, va_list ap)
{
	t_float		d;
	int			exp;
	char		*nbr;
	char		*temp;

	d.d = va_arg(ap, double);
	nbr = ft_check_nan_and_inf(in, d);
	if (nbr)
		return (nbr);
	nbr = ft_unsigned_ll_itoa_base(d.t_bit.mantissa, 'b');
	temp = ft_unsigned_ll_itoa_base(d.t_bit.exponent, 'b');
	exp = ft_binary_str_to_int(temp) - 1023;
	nbr = ft_add_zero_and_hidden_to_mant(nbr, exp);
	nbr = ft_apply_exp_to_mantissa(nbr, exp, d.t_bit.sign, in);
	nbr = ft_keys_width_prec_to_float(in, nbr);
	return (nbr);
}
