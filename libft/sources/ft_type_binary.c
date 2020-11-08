/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:06:44 by geliz             #+#    #+#             */
/*   Updated: 2020/01/06 19:43:28 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_binary(t_info *in, va_list ap)
{
	long long int	nbr;
	char			*ret;

	nbr = va_arg(ap, long long int);
	ret = ft_unsigned_ll_itoa_base(nbr, 'b');
	in->zero = 0;
	if (in->width != -1)
		ret = ft_width_to_int(in, ret);
	return (ret);
}
