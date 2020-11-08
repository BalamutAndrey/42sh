/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:47:36 by geliz             #+#    #+#             */
/*   Updated: 2019/09/21 11:55:07 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = ((char *)(s));
	i = ft_strlen(res);
	if (c == '\0')
		return (&res[i]);
	while (i >= 0)
	{
		if (res[i] == c)
			return (&res[i]);
		i--;
	}
	return (NULL);
}
