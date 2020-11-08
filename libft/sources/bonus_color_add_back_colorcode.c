/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color_add_back_colorcode.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:42:11 by geliz             #+#    #+#             */
/*   Updated: 2020/01/12 14:09:14 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_is_it_backgr_color_part_two(char *str, int i, t_info *in)
{
	char	*ret;

	ret = NULL;
	if (ft_find_color_in_string(&str[i], "{backblue}", 10))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[44m");
		in->base = i + 10;
	}
	if (ft_find_color_in_string(&str[i], "{backmagenta}", 13))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[45m");
		in->base = i + 13;
	}
	if (ft_find_color_in_string(&str[i], "{backcyan}", 10))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[46m");
		in->base = i + 10;
	}
	if (ft_find_color_in_string(&str[i], "{backwhite}", 11))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[47m");
		in->base = i + 11;
	}
	return (ret == NULL ? ft_is_it_end_of_color(str, i, in) : ret);
}

char	*ft_is_it_backgr_color(char *str, int i, t_info *in)
{
	char	*ret;

	ret = NULL;
	if (ft_find_color_in_string(&str[i], "{backblack}", 11))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[40m");
		in->base = i + 11;
	}
	if (ft_find_color_in_string(&str[i], "{backred}", 9))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[41m");
		in->base = i + 9;
	}
	if (ft_find_color_in_string(&str[i], "{backgreen}", 11))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[42m");
		in->base = i + 11;
	}
	if (ft_find_color_in_string(&str[i], "{backyellow}", 12))
	{
		ret = ft_colorcode_join(str, i, in, "\x1b[43m");
		in->base = i + 12;
	}
	return (ret == NULL ? ft_is_it_backgr_color_part_two(str, i, in) : ret);
}
