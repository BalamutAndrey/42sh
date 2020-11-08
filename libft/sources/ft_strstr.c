/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:56:56 by geliz             #+#    #+#             */
/*   Updated: 2019/09/21 18:14:28 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[j])
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return ((char *)&(haystack[i - j]));
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
