/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_check_parts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:05:13 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:17:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_integ(char *integ)
{
	char	*ret;

	if (integ[0] == '\0')
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		ret[0] = '0';
		ft_strdel(&integ);
		return (ret);
	}
	return (integ);
}

char	*ft_add_divis_to_integ(char *integ, char *divis, int sign, t_info *in)
{
	size_t	i;
	size_t	j;
	char	*ret;

	integ = ft_check_integ(integ);
	if (sign == 0 && in->plus == 1)
		sign = 2;
	if (sign == 1)
		in->plus = 1;
	if (!(ret = ft_strnew(ft_strlen(integ) + ft_strlen(divis) + 1 + in->plus)))
		return (NULL);
	i = 0;
	j = 0;
	if (sign != 0)
		ret[j++] = sign == 1 ? '-' : '+';
	while (integ[i] != '\0')
		ret[j++] = integ[i++];
	ret[j++] = '.';
	i = 0;
	while (divis[i] != '\0')
		ret[j++] = divis[i++];
	ft_strdel(&integ);
	ft_strdel(&divis);
	return (ret);
}
