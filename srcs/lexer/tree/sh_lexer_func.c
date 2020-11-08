/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:07:07 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 18:16:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_node	*sh_lexer_create_node(t_main *main, t_token *token, t_type type)
{
	t_node	*new;

	new = sh_memalloc(sizeof(t_node), main);
	new->node_type = type;
	new->token = token;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	sh_lexer_add_node(t_node *node, t_node *left, t_node *right)
{
	if (node != NULL)
	{
		node->left = left;
		node->right = right;
	}
}

void	sh_lexer_del_node(t_node **node)
{
	ft_memdel((void **)node);
}

void	sh_lexer_del_all_node(t_node **node)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *node;
	while (temp)
	{
		temp2 = temp->right;
		sh_lexer_del_node(&temp);
		temp = temp2;
	}
	*node = NULL;
}
