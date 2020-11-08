/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:53:59 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 16:52:38 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_char_null(t_info *in)
{
	char	*ret;

	if (in->width <= 1)
	{
		in->width = 1;
		return (ft_strnew(0));
	}
	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	ret = ft_memset(ret, ' ', in->width);
	if (in->minus == 1)
		ret[0] = '\0';
	else
		ret[in->width - 1] = '\0';
	return (ret);
}

char	*ft_apply_info_to_char(t_info *in, va_list ap)
{
	char	c;
	char	*temp;
	char	*ret;

	if (in->size == L_ || in->size == LL_)
		return (NULL);
	c = va_arg(ap, int);
	if (c != '\0')
	{
		if (!(temp = ft_strnew(1)))
			return (NULL);
		temp[0] = c;
		if (in->width > 1)
		{
			ret = ft_width_to_string(in, temp);
			ft_strdel(&temp);
			return (ret);
		}
	}
	if (c == '\0')
	{
		in->content = CHAR_NULL_;
		temp = ft_apply_info_to_char_null(in);
	}
	return (temp);
}
