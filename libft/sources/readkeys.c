/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readkeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:08:33 by geliz             #+#    #+#             */
/*   Updated: 2020/01/11 18:00:58 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_content(const char *c, int i, t_info *in)
{
	if (c[i] == 'c' || c[i] == 'C')
		in->content = CHAR_;
	if (c[i] == 's')
		in->content = STR_;
	if (c[i] == 'p')
		in->content = PTR_;
	if (c[i] == 'i' || c[i] == 'd')
		in->content = INT_;
	if (c[i] == 'u' || c[i] == 'D')
	{
		in->content = INT_;
		in->unsign = 1;
	}
	if (c[i] == 'o' || c[i] == 'x' || c[i] == 'X')
	{
		in->content = INT_;
		in->base = (int)c[i];
	}
	if (c[i] == 'f' || c[i] == 'F')
		in->content = FLT_;
	if (c[i] == '%')
		in->content = PERCENT_;
	if (c[i] == 'b')
		in->content = BINAR_;
	return (++i);
}

int		ft_size(const char *c, int i, t_info *in)
{
	if (in->size == 0)
	{
		if (c[i] == 'h' && c[i + 1] == 'h')
			in->size = HH_;
		if (c[i] == 'h' && in->size == 0)
			in->size = H_;
		if (c[i] == 'l' && c[i + 1] == 'l')
			in->size = LL_;
		if (c[i] == 'l' && in->size == 0)
			in->size = L_;
		if (c[i] == 'L' && in->size == 0)
			in->size = LBIG_;
	}
	if (in->size == HH_ || in->size == LL_)
		return (i + 2);
	if (in->size == H_ || in->size == L_ || in->size == LBIG_)
		return (i + 1);
	return (i);
}

int		ft_precision(const char *c, int i, t_info *in, va_list ap)
{
	char	*prec;
	int		j;

	j = 0;
	if (in->precision == -1)
	{
		if (c[i] == '.' && c[i + 1] == '*')
		{
			j = va_arg(ap, int);
			in->precision = j >= 0 ? j : -1;
			j = 2;
		}
		else if (c[i] == '.')
		{
			i++;
			while (c[i + j] >= '0' && c[i + j] <= '9')
				j++;
			if (!(prec = ft_strsub(c, i, j)))
				return (0);
			in->precision = j == 0 ? 0 : ft_atoi(prec);
			ft_strdel(&prec);
		}
	}
	return (i + j);
}

int		ft_width(const char *c, int i, t_info *in, va_list ap)
{
	char	*wid;
	int		j;

	j = 0;
	if (in->width == -1)
	{
		if (c[i] >= '1' && c[i] <= '9')
		{
			while (c[i + j] >= '0' && c[i + j] <= '9')
				j++;
			if (!(wid = ft_strsub(c, i, j)))
				return (0);
			in->width = ft_atoi(wid);
			ft_strdel(&wid);
		}
		else if (c[i] == '*')
		{
			j = va_arg(ap, int);
			if (j < 0)
				in->minus = 1;
			in->width = j > 0 ? j : j * -1;
			j = 1;
		}
	}
	return (i + j);
}

int		ft_flags(const char *c, int i, t_info *in)
{
	while (c[i] == '-' || c[i] == '+' || c[i] == ' ' ||
			c[i] == '#' || c[i] == '0')
	{
		if (c[i] == '-')
			in->minus = 1;
		if (c[i] == '+')
			in->plus = 1;
		if (c[i] == ' ')
			in->space = 1;
		if (c[i] == '#')
			in->octotorp = 1;
		if (c[i] == '0')
			in->zero = 1;
		i++;
	}
	return (i);
}
