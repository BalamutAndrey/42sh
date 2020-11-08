/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:22:22 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:25:45 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_to_float(t_info *in, char *nbr)
{
	int		len;
	int		af_dot;
	char	*ret;
	int		i;

	len = 0;
	af_dot = 0;
	while (nbr[len] != '.')
		len++;
	len++;
	if (in->precision == 0)
		ret = ft_precision_float_zero(nbr, len, in);
	i = len;
	while (nbr[i++] != '\0')
		af_dot++;
	if (in->precision == -1)
		in->precision = 6;
	if (in->precision > 0 && in->precision == af_dot)
		return (nbr);
	if (in->precision > af_dot)
		ret = ft_precision_more_add_zero(nbr, len, af_dot, in->precision);
	if (in->precision > 0 && in->precision < af_dot)
		ret = ft_precision_less_cut_str(nbr, len, in->precision);
	return (ret);
}

char	*ft_keys_width_prec_to_float(t_info *in, char *nbr)
{
	char	*ret;

	ret = nbr;
	ret = ft_precision_to_float(in, nbr);
	if (ret != NULL && in->width > ((int)ft_strlen(ret) - 1))
		ret = ft_width_to_float(in, ret);
	if (ret && in->space == 1 && in->width < ((int)ft_strlen(ret) - 1))
		ret = ft_keys_space_to_float(in, ret);
	if (ret)
		return (ret);
	else
		return (nbr);
}
