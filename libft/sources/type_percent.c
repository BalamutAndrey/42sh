/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:46:25 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 14:52:32 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_percent(t_info *in)
{
	char	*ret;
	char	*temp_space;
	char	fill;

	if (in->width > 1)
	{
		if (!(temp_space = ft_strnew(in->width - 1)))
			return (NULL);
		fill = in->zero == 1 && in->minus != 1 ? '0' : ' ';
		temp_space = ft_memset(temp_space, fill, in->width - 1);
		if (in->minus == 1)
			ret = ft_strjoin("%", temp_space);
		else
			ret = ft_strjoin(temp_space, "%");
		ft_strdel(&temp_space);
		return (ret);
	}
	ret = ft_strsub("%", 0, 1);
	return (ret);
}
