/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:22:53 by geliz             #+#    #+#             */
/*   Updated: 2019/09/27 14:43:12 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_cleanstr(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

static char	**ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;
	char	**str;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			if ((s[i + 1] == c) || (s[i + 1] == '\0'))
				w++;
			i++;
		}
	}
	str = malloc(sizeof(char *) * (w + 1));
	if (str == NULL)
		return (NULL);
	str[w] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	mas;
	size_t	wlen;
	size_t	i;
	char	**str;

	if (s == NULL)
		return (NULL);
	mas = 0;
	wlen = 0;
	i = 0;
	if (!(str = ft_count_words(s, c)))
		return (NULL);
	while (s[mas] != '\0')
	{
		if (s[mas] != c)
			wlen++;
		mas++;
		if (wlen > 0 && (s[mas] == c || s[mas] == '\0'))
		{
			if (!(str[i++] = ft_strsub(s, ((unsigned int)(mas - wlen)), wlen)))
				return (ft_cleanstr(str, i));
			wlen = 0;
		}
	}
	return (str);
}
