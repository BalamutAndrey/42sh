/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:45:16 by geliz             #+#    #+#             */
/*   Updated: 2019/09/13 19:40:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	res = ((char *)(s));
	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == c)
			return (&res[i]);
		i++;
	}
	if ((res[i] == '\0') && (c == '\0'))
		return (&res[i]);
	return (NULL);
}
