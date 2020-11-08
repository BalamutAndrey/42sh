/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_hub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:58:08 by geliz             #+#    #+#             */
/*   Updated: 2020/08/02 16:31:38 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(int fd, const char *c, ...)
{
	t_info		*info;
	va_list		ap;
	char		*str;
	int			ret;

	if (fd == -1)
		return (0);
	info = NULL;
	if (!(info = ft_create_info(info, 0)))
		return (-1);
	va_start(ap, c);
	str = ft_printf_cycle(c, info, ap);
	if (!str)
		return (0);
	write(fd, str, info->position);
	ft_strdel(&str);
	va_end(ap);
	ret = info->position;
	free(info);
	return (ret);
}

int		ft_colorprintf(const char *c, ...)
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
	if (!str)
		return (0);
	info->position = ft_add_colors_to_text(str, info);
	ret = info->position;
	va_end(ap);
	free(info);
	info = NULL;
	return (ret);
}
