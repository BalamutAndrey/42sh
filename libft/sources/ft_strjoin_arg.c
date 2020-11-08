/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:07:59 by geliz             #+#    #+#             */
/*   Updated: 2020/10/25 16:44:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_str_value_strjoin_arg(char *ret, char *temp)
{
	char	*val;

	if (!ret && !temp)
		return (NULL);
	if (!ret)
	{
		val = ft_strdup(temp);
		if (!val)
			ft_fprintf(2, "Malloc error in strjoin_arg\n");
		return (val);
	}
	if (!temp)
	{
		val = ft_strdup(ret);
		if (!val)
			ft_fprintf(2, "Malloc error in strjoin_arg\n");
		return (val);
	}
	val = ft_strjoin(ret, temp);
	if (!val)
		ft_fprintf(2, "Malloc error in strjoin_arg\n");
	return (val);
}

char	*ft_strjoin_arg(const char *s, ...)
{
	char	*ret;
	va_list	ap;
	char	*temp;
	char	*temp_ret;

	ret = NULL;
	temp_ret = NULL;
	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			temp = va_arg(ap, char *);
			temp_ret = ft_check_str_value_strjoin_arg(ret, temp);
			ft_strdel(&ret);
			ret = temp_ret;
			if ((*s + 1) == 'f')
				ft_strdel(&temp);
		}
		s++;
	}
	va_end(ap);
	return (ret);
}
