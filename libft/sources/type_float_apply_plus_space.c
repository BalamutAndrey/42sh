/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_plus_space.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:45:42 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:25:03 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_keys_space_to_float(t_info *in, char *nbr)
{
	int		len;
	char	*ret;

	ret = NULL;
	if (nbr[0] == '-')
		return (nbr);
	len = (int)ft_strlen(nbr);
	if (in->plus == 0 && in->space == 1)
	{
		if (!(ret = ft_strnew(len + 1)))
			return (NULL);
		ret[0] = ' ';
		ft_strcat(&ret[1], nbr);
		ft_strdel(&nbr);
		return (ret);
	}
	return (nbr);
}
