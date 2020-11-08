/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_lib_newstrings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:39:25 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 16:30:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char			*str;

	if (size + 1 == 0)
		return (NULL);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size);
	str[size] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char			*dest;
	size_t			z;
	size_t			i;

	z = ft_strlen(src);
	dest = malloc(sizeof(char) * (z + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i != (z + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] != '\0') && (i < start))
		i++;
	if (i != start)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((s[i] != '\0') && (j < len))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (j != len)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*str;
	size_t			i;

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
	return (str);
}
