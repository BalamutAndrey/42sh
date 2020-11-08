/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:26:09 by geliz             #+#    #+#             */
/*   Updated: 2020/01/11 15:15:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (src == NULL && dst == NULL)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin_spec(char *base, char *arg, t_info *in, int len_base)
{
	int				len_arg;
	char			*ret;

	if (!arg)
	{
		in->position = 0;
		return (base);
	}
	if (in->content != CHAR_NULL_)
		len_arg = (int)ft_strlen(arg);
	else
		len_arg = in->width;
	if (!(ret = ft_strnew(len_base + len_arg)))
		return (NULL);
	in->position = len_arg;
	if (base)
		ret = ft_memcpy(ret, base, len_base);
	ft_memcpy(&ret[len_base], arg, len_arg);
	ft_strdel(&base);
	ft_strdel(&arg);
	return (ret);
}
