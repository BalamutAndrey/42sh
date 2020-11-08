/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int_width_and_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:25:33 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 16:30:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_with_space_to_int(t_info *in, char *ret)
{
	char		*temp;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	len = ft_strlen(ret);
	if (!(temp = ft_strnew(in->width)))
		return (NULL);
	while (in->width > j)
	{
		while (in->width > (len + j))
			temp[j++] = ' ';
		temp[j++] = ret[i++];
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_width_with_zero_to_int(t_info *in, char *ret)
{
	char		*temp;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	len = ft_strlen(ret);
	if (!(temp = ft_strnew(in->width)))
		return (NULL);
	if ((in->base == 'x' || in->base == 'X') && in->octotorp == 1)
		return (ft_width_with_zero_to_hexadec_int(in, temp, ret, len));
	if (ret[0] == '-' || ret[0] == '+' || ret[0] == ' ')
	{
		temp[j++] = ret[i++];
		len--;
	}
	while (in->width > j)
	{
		while (in->width > (len + j))
			temp[j++] = '0';
		temp[j++] = ret[i++];
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_width_with_minus_to_int(t_info *in, char *ret)
{
	char		c;
	int			i;
	int			j;
	char		*temp;

	if (!(temp = ft_strnew(in->width)))
		return (NULL);
	c = ' ';
	i = 0;
	j = 0;
	while (ret[i] != '\0')
		temp[j++] = ret[i++];
	while (in->width > j)
		temp[j++] = c;
	ft_strdel(&ret);
	return (temp);
}

char	*ft_width_to_int(t_info *in, char *ret)
{
	char		*temp;
	int			len;

	temp = NULL;
	len = (int)ft_strlen(ret);
	if (in->width > len)
	{
		if (in->minus == 1)
			temp = ft_width_with_minus_to_int(in, ret);
		else
		{
			if (in->zero == 1)
				temp = ft_width_with_zero_to_int(in, ret);
			if (!temp)
				temp = ft_width_with_space_to_int(in, ret);
		}
		return (temp);
	}
	else
		return (ret);
}

char	*ft_space_to_int(t_info *in, char *ret)
{
	char		*temp;
	size_t		len;
	int			j;
	int			i;

	j = 0;
	i = 0;
	if (in->plus == 1 || ret[0] == '-')
		return (ret);
	len = ft_strlen(ret);
	if (!(temp = ft_strnew(len + 1)))
		return (NULL);
	temp[i] = ' ';
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
