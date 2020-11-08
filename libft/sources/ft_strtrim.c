/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:03:54 by geliz             #+#    #+#             */
/*   Updated: 2019/09/21 20:13:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	send;
	size_t	sbeg;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	sbeg = 0;
	send = 1;
	while ((s[sbeg] == ' ') || (s[sbeg] == '\n') || (s[sbeg] == '\t'))
		sbeg++;
	if (s[sbeg] == '\0')
	{
		str = ft_strnew(1);
		return (str == NULL ? NULL : str);
	}
	while ((s[len - send] == ' ') || (s[len - send] == '\n') ||
			(s[len - send] == '\t'))
		send++;
	str = ft_strsub(s, sbeg, (len - sbeg - send + 1));
	if (str == NULL)
		return (NULL);
	str[len - sbeg - send + 1] = '\0';
	return (str);
}
