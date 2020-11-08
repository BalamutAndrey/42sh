/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:12:42 by geliz             #+#    #+#             */
/*   Updated: 2020/01/24 20:15:13 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_without_minus(t_info *in, char *str, char *ret)
{
	int		i;
	char	c;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	c = in->zero == 1 ? '0' : ' ';
	while (i < (in->width - (int)len))
	{
		ret[i] = c;
		i++;
	}
	len = 0;
	while (str[len] != '\0')
	{
		ret[i] = str[len];
		len++;
		i++;
	}
	return (ret);
}

char	*ft_width_with_minus(t_info *in, char *str, char *ret)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	while (i < in->width)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}

char	*ft_width_to_string(t_info *in, char *str)
{
	char	*ret;

	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	if (in->minus == 1)
		ret = ft_width_with_minus(in, str, ret);
	else
		ret = ft_width_without_minus(in, str, ret);
	ft_strdel(&str);
	return (ret);
}

char	*ft_precision_to_string(t_info *in, char *str)
{
	char	*ret;

	if (in->precision == 0)
	{
		if (!(ret = ft_strnew(0)))
			return (NULL);
		ft_strdel(&str);
		return (ret);
	}
	if (!(ret = ft_strsub(str, 0, in->precision)))
		return (NULL);
	ft_strdel(&str);
	return (ret);
}

char	*ft_apply_info_to_string(t_info *in, va_list ap)
{
	char	*str;
	char	*ret;
	char	*temp;
	size_t	j;

	if (in->size == L_ || in->size == LL_)
		return (NULL);
	temp = va_arg(ap, char *);
	str = temp == NULL ? ft_strdup("(null)") : ft_strdup(temp);
	j = ft_strlen(str);
	if (in->precision >= 0 && (int)j > in->precision)
		str = ft_precision_to_string(in, str);
	j = ft_strlen(str);
	if (in->width >= 0 && (int)j < in->width)
		str = ft_width_to_string(in, str);
	if (!(ret = ft_strdup(str)))
		return (NULL);
	ft_strdel(&str);
	return (ret);
}
