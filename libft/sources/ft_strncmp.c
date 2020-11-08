/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:00:23 by geliz             #+#    #+#             */
/*   Updated: 2019/09/14 16:17:21 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) && (i < n)
			&& (s1[i] != '\0') && (s2[i] != '\0'))
	{
		i++;
		if (i == n)
			return (0);
	}
	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	else
		return (0);
}
