/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:24:29 by geliz             #+#    #+#             */
/*   Updated: 2019/09/21 12:38:07 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*tempn;

	temp = *alst;
	while (temp != NULL)
	{
		tempn = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = tempn;
	}
	*alst = NULL;
}
