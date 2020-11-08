/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int_convert_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:37:10 by geliz             #+#    #+#             */
/*   Updated: 2020/01/06 18:30:46 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_sized_h_hh_int_to_str(t_info *in, va_list ap)
{
	char					*ret;
	int						temp;
	char					c;
	short int				nbr;

	if (in->size == H_)
	{
		temp = va_arg(ap, int);
		nbr = (short int)temp;
		ret = ft_ll_itoa(nbr);
	}
	if (in->size == HH_)
	{
		c = va_arg(ap, int);
		temp = (int)c;
		ret = ft_ll_itoa(temp);
	}
	return (ret);
}

char	*ft_convert_unsigned_sized_h_hh_int_to_str(t_info *in, va_list ap)
{
	char					*ret;
	int						temp;
	unsigned char			c;
	unsigned short int		nbr;

	if (in->size == H_)
	{
		temp = va_arg(ap, int);
		nbr = (unsigned short int)temp;
		ret = ft_unsigned_ll_itoa_base(nbr, in->base);
	}
	if (in->size == HH_)
	{
		c = va_arg(ap, int);
		temp = (int)c;
		ret = ft_unsigned_ll_itoa_base(temp, in->base);
	}
	return (ret);
}

char	*ft_convert_unsigned_sized_int_to_str(t_info *in, va_list ap)
{
	char					*ret;
	unsigned long int		u_li_nbr;
	unsigned long long int	u_lli_nbr;

	if (in->size == H_ || in->size == HH_)
	{
		ret = ft_convert_unsigned_sized_h_hh_int_to_str(in, ap);
		return (ret);
	}
	if (in->size == L_)
	{
		u_li_nbr = va_arg(ap, unsigned long int);
		ret = ft_unsigned_ll_itoa_base(u_li_nbr, in->base);
	}
	if (in->size == LL_)
	{
		u_lli_nbr = va_arg(ap, unsigned long long int);
		ret = ft_unsigned_ll_itoa_base(u_lli_nbr, in->base);
	}
	return (ret);
}

char	*ft_convert_sized_int_to_str(t_info *in, va_list ap)
{
	char					*ret;
	long int				li_nbr;
	long long int			lli_nbr;

	if (in->unsign == 1)
	{
		ret = ft_convert_unsigned_sized_int_to_str(in, ap);
		return (ret);
	}
	if (in->size == H_ || in->size == HH_)
	{
		ret = ft_convert_sized_h_hh_int_to_str(in, ap);
		return (ret);
	}
	if (in->size == L_)
	{
		li_nbr = va_arg(ap, long int);
		ret = ft_ll_itoa(li_nbr);
	}
	if (in->size == LL_)
	{
		lli_nbr = va_arg(ap, long long int);
		ret = ft_ll_itoa(lli_nbr);
	}
	return (ret);
}

char	*ft_convert_int_to_str(t_info *in, va_list ap)
{
	char						*ret;
	int							i_nbr;
	unsigned int				u_nbr;

	ret = NULL;
	if (in->base != 'd')
		in->unsign = 1;
	if (in->size != 0)
	{
		ret = ft_convert_sized_int_to_str(in, ap);
		return (ret);
	}
	if (in->unsign == 0 && in->base == 'd')
	{
		i_nbr = va_arg(ap, int);
		ret = ft_ll_itoa(i_nbr);
	}
	else
	{
		u_nbr = va_arg(ap, unsigned int);
		ret = ft_unsigned_ll_itoa_base(u_nbr, in->base);
	}
	return (ret);
}
