/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:51:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 15:59:20 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_to_ptr(t_info *in, char *ret)
{
	char					*temp_space;
	char					*temp_str;

	temp_space = ft_strnew(in->width - (int)ft_strlen(ret));
	temp_space = ft_memset(temp_space, ' ', (in->width - (int)ft_strlen(ret)));
	if (!(temp_str = ft_strdup(ret)))
	{
		ft_strdel(&ret);
		return (NULL);
	}
	ft_strdel(&ret);
	if (in->minus == 1)
		ret = ft_strjoin(temp_str, temp_space);
	else
		ret = ft_strjoin(temp_space, temp_str);
	ft_strdel(&temp_space);
	ft_strdel(&temp_str);
	return (ret);
}

char	*ft_precision_to_ptr(t_info *in, char *ret)
{
	char					*temp_zero;
	char					*temp_str;

	temp_zero = ft_strnew(in->precision - (int)ft_strlen(ret));
	temp_zero = ft_memset(temp_zero, '0', (in->precision -
		(int)ft_strlen(ret)));
	if (!(temp_str = ft_strdup(ret)))
	{
		ft_strdel(&ret);
		return (NULL);
	}
	ft_strdel(&ret);
	ret = ft_strjoin(temp_zero, temp_str);
	ft_strdel(&temp_zero);
	ft_strdel(&temp_str);
	return (ret);
}

char	*ft_apply_info_to_ptr(t_info *in, va_list ap)
{
	unsigned long int		ptr;
	char					*ret;
	char					*temp_str;
	char					*temp_space;

	ptr = va_arg(ap, unsigned long int);
	temp_str = ft_unsigned_ll_itoa_base(ptr, 'x');
	if (in->precision > (int)ft_strlen(temp_str))
		temp_str = ft_precision_to_ptr(in, temp_str);
	temp_space = ft_strsub("0x", 0, 2);
	if (in->precision == 0 && ptr == 0)
		ret = ft_strdup(temp_space);
	else
		ret = ft_strjoin(temp_space, temp_str);
	ft_strdel(&temp_space);
	ft_strdel(&temp_str);
	if (in->width > (int)ft_strlen(ret))
		ret = ft_width_to_ptr(in, ret);
	return (ret);
}
