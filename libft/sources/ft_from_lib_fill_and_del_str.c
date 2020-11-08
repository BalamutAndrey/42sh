/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_lib_fill_and_del_str.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:04:27 by geliz             #+#    #+#             */
/*   Updated: 2020/11/06 18:19:52 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	z;
	size_t			i;

	i = 0;
	z = c;
	while (len != 0)
	{
		((char *)b)[i] = z;
		i++;
		len--;
	}
	return (b);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	z;

	i = ft_strlen(s1);
	z = 0;
	while (s2[z] != '\0')
	{
		s1[i] = s2[z];
		i++;
		z++;
	}
	s1[i] = '\0';
	return (s1);
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		ft_memset(*as, 0, ft_strlen(*as));
		free(*as);
		*as = NULL;
	}
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (i == len)
		return (dst);
	else
	{
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}
