/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:33:42 by eboris            #+#    #+#             */
/*   Updated: 2020/07/19 18:18:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*ft_strmbncpy(char *src, int i)
{
	int		n;
	char	*s;

	n = 0;
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (n < i)
	{
		s[n] = src[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

char	*ft_strmancpy(char *src, int i)
{
	int		n;
	char	*s;

	n = 0;
	s = (char *)malloc((ft_strlen(src) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (src[i] != '\0')
	{
		s[n] = src[i];
		n++;
		i++;
	}
	s[n] = '\0';
	ft_strdel(&src);
	return (s);
}

char	*ft_strsdup(char *b, char *a)
{
	char	*fin;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fin = malloc((ft_strlen(b) + ft_strlen(a) + 1) * sizeof(char));
	if (!fin)
		return (NULL);
	while (b[x] != '\0')
	{
		fin[x] = b[x];
		x++;
	}
	while (a[y] != '\0')
	{
		fin[x + y] = a[y];
		y++;
	}
	fin[x + y] = '\0';
	ft_strdel(&b);
	ft_strdel(&a);
	return (fin);
}
