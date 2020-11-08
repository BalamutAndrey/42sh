/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 16:33:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_content(t_info *in, va_list ap)
{
	char	*str;

	str = NULL;
	if (in->size == LBIG_ && in->content != FLT_)
		in->size = LL_;
	if (in->content == PERCENT_)
		str = ft_apply_info_to_percent(in);
	if (in->content == CHAR_)
		str = ft_apply_info_to_char(in, ap);
	if (in->content == STR_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == PTR_)
		str = ft_apply_info_to_ptr(in, ap);
	if (in->content == INT_)
		str = ft_apply_info_to_int(in, ap);
	if (in->content == FLT_ && in->size != LBIG_)
		str = ft_apply_info_to_flt(in, ap);
	if (in->content == FLT_ && in->size == LBIG_)
		str = ft_apply_info_to_flt_long(in, ap);
	if (in->content == BINAR_)
		str = ft_apply_info_to_binary(in, ap);
	return (str);
}
