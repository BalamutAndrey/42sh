/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:51:22 by geliz             #+#    #+#             */
/*   Updated: 2019/09/27 14:30:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	temp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
			return (NULL);
		temp = temp->next;
	}
	return (new);
}
