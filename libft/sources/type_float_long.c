/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:45:31 by geliz             #+#    #+#             */
/*   Updated: 2020/01/04 14:52:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_nan_and_inf_long(t_info *in, t_lfloat d)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	if (d.ld != d.ld)
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
	if (d.t_lbit.exponent == 32767)
	{
		return (ret = ft_keys_to_inf(in, ret, d.t_lbit.sign));
	}
	return (NULL);
}

char	*ft_apply_info_to_flt_long(t_info *in, va_list ap)
{
	t_lfloat	d;
	int			exp;
	char		*nbr;
	char		*temp;

	d.ld = va_arg(ap, long double);
	nbr = ft_check_nan_and_inf_long(in, d);
	if (nbr)
		return (nbr);
	nbr = ft_unsigned_ll_itoa_base(d.t_lbit.mantissa, 'b');
	temp = ft_unsigned_ll_itoa_base(d.t_lbit.exponent, 'b');
	exp = ft_binary_str_to_int(temp) - 16383;
	nbr = ft_apply_exp_to_mantissa(nbr, exp, d.t_lbit.sign, in);
	nbr = ft_keys_width_prec_to_float(in, nbr);
	return (nbr);
}
