/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:14:04 by geliz             #+#    #+#             */
/*   Updated: 2020/01/12 13:47:30 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*str;
	size_t			i;

	if (s1 == NULL)
		return (s2);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	str = ft_strnew(lens1 + lens2);
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
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}

int		ft_add_colors_to_text(char *str, t_info *in)
{
	int		i;
	int		limit;
	char	*temp;
	char	*ret;

	limit = in->position;
	in->base = 0;
	i = 0;
	ret = NULL;
	while (i < limit)
	{
		if (str[i] == '{')
		{
			temp = ft_is_it_color(str, i, in);
			if (temp)
				ret = ft_strjoin_free(ret, temp);
		}
		i++;
	}
	ft_strdel(&str);
	i = (int)ft_strlen(ret);
	write(1, ret, i);
	ft_strdel(&ret);
	return (i);
}
