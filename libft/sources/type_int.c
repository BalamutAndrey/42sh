/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:41:58 by geliz             #+#    #+#             */
/*   Updated: 2020/01/12 13:18:31 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plus_to_int(char *ret)
{
	char		*temp;
	size_t		len;
	int			j;
	int			i;

	len = ft_strlen(ret);
	j = 0;
	i = 0;
	if (ret[0] != '-')
	{
		if (!(temp = ft_strnew(len + 1)))
			return (NULL);
		temp[i] = '+';
		i++;
		while (ret[j] != '\0')
		{
			temp[i] = ret[j];
			i++;
			j++;
		}
		ft_strdel(&ret);
		return (temp);
	}
	return (ret);
}

int		ft_is_nmb_zero(t_info *in, char *ret)
{
	if (in->base == 'o' && in->octotorp == 1)
		return (0);
	if (ft_strlen(ret) > 1)
		return (0);
	if (ret[0] == '0')
	{
		ft_strdel(&ret);
		return (1);
	}
	return (0);
}

char	*ft_precision_to_int_negative(t_info *in, char *ret, int len)
{
	char		*temp;
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (!(temp = ft_strnew(++in->precision)))
		return (NULL);
	temp[0] = '-';
	ret[0] = '0';
	while (in->precision > i)
	{
		while (in->precision > (len + i))
			temp[i++] = '0';
		temp[i++] = ret[j++];
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_precision_to_int(t_info *in, char *ret)
{
	char		*temp;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(ret);
	if (in->octotorp == 1 && in->precision > (len - 2) && (in->base == 'x' ||
		in->base == 'X'))
		return (ft_precision_to_int_base_hexadec(in, ret, len));
	if (ret[j] == '-' && in->precision > (len - 1))
		return (ft_precision_to_int_negative(in, ret, len));
	if (in->precision <= len)
		return (ret);
	if (!(temp = ft_strnew(in->precision)))
		return (NULL);
	while (in->precision > i)
	{
		while (in->precision > (len + i))
			temp[i++] = '0';
		temp[i++] = ret[j++];
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_apply_info_to_int(t_info *in, va_list ap)
{
	char		*ret;

	if (!(ret = ft_convert_int_to_str(in, ap)))
		return (NULL);
	if (in->precision != -1)
		in->zero = 0;
	if (ret != NULL && in->octotorp == 1 && in->base != 'd')
		ret = ft_octotorp_to_int(in, ret);
	if (ret != NULL && in->precision != -1)
		ret = ft_precision_to_int(in, ret);
	if (ret != NULL && in->precision == 0 && (ft_is_nmb_zero(in, ret) == 1))
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1 && in->unsign == 0)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1 && in->unsign == 0)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
		ret = ft_width_to_int(in, ret);
	return (ret);
}
