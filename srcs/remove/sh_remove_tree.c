/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:55:15 by eboris            #+#    #+#             */
/*   Updated: 2020/11/02 18:36:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_tree(t_main *main)
{
	if (main->tree_first != NULL)
	{
		sh_remove_node(main->tree_first);
		main->tree_first = NULL;
	}
	main->tree_curr = NULL;
}

void	sh_remove_node(t_node *node)
{
	if (node->right != NULL)
	{
		sh_remove_node(node->right);
		node->right = NULL;
	}
	if (node->left != NULL)
	{
		sh_remove_node(node->left);
		node->left = NULL;
	}
	node->token = NULL;
	free(node);
	node = NULL;
}
