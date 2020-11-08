/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strjoin_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:59:17 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 17:08:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_strjoin(char const *s1, char const *s2, t_main *main)
{
	size_t			lens1;
	size_t			lens2;
	char			*str;
	size_t			i;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	str = sh_strnew(lens1 + lens2, main);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s1, lens1);
	i = 0;
	while (s2[i] != '\0')
	{
		str[lens1 + i] = s2[i];
		i++;
	}
	str[lens1 + i] = '\0';
	return (str);
}

char	*sh_check_str_value_strjoin_arg(char *ret, char *temp, t_main *main)
{
	char	*val;

	if (!ret && !temp)
		return (NULL);
	if (!ret)
	{
		val = sh_strdup(temp, main);
		return (val);
	}
	if (!temp)
	{
		val = sh_strdup(ret, main);
		return (val);
	}
	val = sh_strjoin(ret, temp, main);
	return (val);
}

char	*sh_strjoin_arg(t_main *main, const char *s, ...)
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
			temp_ret = sh_check_str_value_strjoin_arg(ret, temp, main);
			ft_strdel(&ret);
			ret = temp_ret;
			if (*(s + 1) == 'f')
				ft_strdel(&temp);
		}
		s++;
	}
	va_end(ap);
	return (ret);
}
