/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color_add_colorcode.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:03:07 by geliz             #+#    #+#             */
/*   Updated: 2020/01/12 13:47:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_find_color_in_string(char *str, char *color, int len)
{
	int		i;

	i = 0;
	while (i < len && str[i] == color[i])
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	if (i == len)
		return (str);
	return (NULL);
}

char	*ft_colorcode_join(char *str, int i, t_info *in, char *color)
{
	char	*ret;
	char	*temp;

	temp = ft_strsub(str, in->base, i - in->base);
	ret = ft_strjoin(temp, color);
	ft_strdel(&temp);
	return (ret);
}

char	*ft_is_it_end_of_color(char *str, int i, t_info *in)
{
	char	*ret;

	ret = NULL;
	if (ft_find_color_in_string(&str[i], "{eoc}", 5))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[0m");
		in->base = i + 5;
	}
	return (ret);
}

char	*ft_is_it_color_part_two(char *str, int i, t_info *in)
{
	char	*ret;

	ret = NULL;
	if (ft_find_color_in_string(&str[i], "{blue}", 6))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[34m");
		in->base = i + 6;
	}
	if (ft_find_color_in_string(&str[i], "{magenta}", 9))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[35m");
		in->base = i + 9;
	}
	if (ft_find_color_in_string(&str[i], "{cyan}", 6))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[36m");
		in->base = i + 6;
	}
	if (ft_find_color_in_string(&str[i], "{white}", 7))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[37m");
		in->base = i + 7;
	}
	return (ret == NULL ? ft_is_it_backgr_color(str, i, in) : ret);
}

char	*ft_is_it_color(char *str, int i, t_info *in)
{
	char	*ret;

	ret = NULL;
	if (ft_find_color_in_string(&str[i], "{black}", 7))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[30m");
		in->base = i + 7;
	}
	if (ft_find_color_in_string(&str[i], "{red}", 5))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[31m");
		in->base = i + 5;
	}
	if (ft_find_color_in_string(&str[i], "{green}", 7))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[32m");
		in->base = i + 7;
	}
	if (ft_find_color_in_string(&str[i], "{yellow}", 8))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[33m");
		in->base = i + 8;
	}
	return (ret == NULL ? ft_is_it_color_part_two(str, i, in) : ret);
}
