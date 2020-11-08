/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:29:03 by geliz             #+#    #+#             */
/*   Updated: 2020/01/11 18:49:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_readkeys_and_type(int i, t_info *info, const char *c, va_list ap)
{
	if (c[i] == '%')
	{
		i++;
		i = ft_flags(c, i, info);
		if ((i = ft_width(c, i, info, ap)) == 0)
			return (-1);
		if ((i = ft_precision(c, i, info, ap)) == 0)
			return (-1);
		i = ft_size(c, i, info);
		while (info->content == 0 && c[i] != '\0')
			i = ft_content(c, i, info);
	}
	return (i);
}

char	*ft_print_base(char *res, const char *c, int i, t_info *in)
{
	int		j;
	char	*str;

	j = 0;
	str = NULL;
	while (c[i + j] != '%' && c[i + j] != '\0')
		j++;
	if (j != 0)
		str = ft_strsub(c, i, j);
	res = ft_strjoin_spec(res, str, in, in->position);
	in->position = j;
	return (res);
}

t_info	*ft_create_info(t_info *in, int symb)
{
	if (!in)
		in = malloc(sizeof(t_info));
	in->minus = 0;
	in->plus = 0;
	in->space = 0;
	in->octotorp = 0;
	in->zero = 0;
	in->width = -1;
	in->precision = -1;
	in->size = 0;
	in->content = 0;
	in->unsign = 0;
	in->base = 'd';
	in->position = symb;
	return (in);
}

char	*ft_printf_cycle(const char *c, t_info *in, va_list ap)
{
	int			count_symb;
	char		*res;
	int			i;

	i = 0;
	count_symb = 0;
	res = NULL;
	while (c[i] != '\0')
	{
		in = ft_create_info(in, count_symb);
		res = ft_print_base(res, c, i, in);
		count_symb += in->position;
		i += in->position;
		if ((i = ft_readkeys_and_type(i, in, c, ap)) == -1)
			return (NULL);
		if (in->content != 0)
		{
			res = ft_strjoin_spec(res, ft_check_content(in, ap), in,
				count_symb);
			count_symb += in->position;
		}
	}
	in->position = count_symb;
	return (res);
}

int		ft_printf(const char *c, ...)
{
	t_info		*info;
	va_list		ap;
	char		*str;
	int			ret;

	info = NULL;
	if (!(info = ft_create_info(info, 0)))
		return (-1);
	va_start(ap, c);
	str = ft_printf_cycle(c, info, ap);
	ret = str ? info->position : 0;
	if (ret != 0)
		write(1, str, info->position);
	ft_strdel(&str);
	va_end(ap);
	free(info);
	info = NULL;
	return (ret);
}
