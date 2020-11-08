/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_keys_to_spec.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:35:14 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 17:27:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_to_inf_or_nan(t_info *in, char *str)
{
	char	*temp_space;
	char	*ret;

	if (!(temp_space = ft_strnew(in->width - (int)ft_strlen(str))))
		return (NULL);
	temp_space = ft_memset(temp_space, ' ', (in->width - (int)ft_strlen(str)));
	if (in->minus == 1)
		ret = ft_strjoin(str, temp_space);
	else
		ret = ft_strjoin(temp_space, str);
	ft_strdel(&temp_space);
	return (ret);
}

char	*ft_keys_to_inf(t_info *in, char *ret, unsigned int sign)
{
	char	*temp_inf;

	if (sign == 1)
		temp_inf = ft_strsub("-inf", 0, 4);
	else if (in->plus == 1)
		temp_inf = ft_strsub("+inf", 0, 4);
	else if (in->space == 1)
		temp_inf = ft_strsub(" inf", 0, 4);
	else
		temp_inf = ft_strsub("inf", 0, 3);
	if (temp_inf == NULL)
		return (NULL);
	if (in->width > (int)ft_strlen(temp_inf))
	{
		ret = ft_width_to_inf_or_nan(in, temp_inf);
		ft_strdel(&temp_inf);
		return (ret);
	}
	return (temp_inf);
}
