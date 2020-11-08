/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:14:12 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:23:08 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_without_minus_to_float(t_info *in, char *str)
{
	char	*ret;
	char	c;
	int		len;
	int		i;
	int		count;

	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	i = 0;
	if (in->space == 1)
		ret[i] = ' ';
	if (in->zero == 1 && (str[i] == '+' || str[i] == '-'))
	{
		ret[i] = str[i];
		in->space = 0;
		i++;
	}
	len = (int)ft_strlen(str);
	c = in->zero == 1 ? '0' : ' ';
	if ((count = in->width - len - in->space) < 0)
		count = 0;
	ft_memset(&ret[i + in->space], c, count);
	ft_strcat(&ret[in->width - len], &str[i]);
	ft_strdel(&str);
	return (ret);
}

char	*ft_width_with_minus_to_float(t_info *in, char *str)
{
	char	*ret;
	char	c;
	int		len;
	int		i;
	int		count;

	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	i = 0;
	if (in->space == 1 && str[0] != '-')
		ret[i++] = ' ';
	len = (int)ft_strlen(str);
	c = ' ';
	if ((count = in->width - len - i) < 0)
		count = 0;
	ft_strcat(&ret[i], str);
	ft_memset(&ret[len + i], c, count);
	ft_strdel(&str);
	return (ret);
}

char	*ft_width_to_float(t_info *in, char *str)
{
	char	*ret;

	ret = str;
	if (in->minus == 1)
		ret = ft_width_with_minus_to_float(in, ret);
	else
		ret = ft_width_without_minus_to_float(in, ret);
	return (ret);
}
