/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_malloc_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:43:31 by geliz             #+#    #+#             */
/*   Updated: 2020/11/04 16:16:00 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	*sh_memalloc(size_t size, t_main *main)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		sh_exit(main, 0);
	ft_memset(res, 0, size);
	return (res);
}

char	*sh_strdup(const char *src, t_main *main)
{
	char			*dest;
	size_t			z;
	size_t			i;

	z = ft_strlen(src);
	dest = sh_memalloc(sizeof(char) * (z + 1), main);
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

char	*sh_strsub(const char *s, unsigned int start, size_t len, t_main *main)
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
	if (!(str = sh_memalloc(sizeof(char) * (len + 1), main)))
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

char	*sh_strnew(size_t size, t_main *main)
{
	char			*str;

	if (size + 1 == 0)
		return (NULL);
	str = sh_memalloc(sizeof(char) * (size + 1), main);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	return (str);
}
