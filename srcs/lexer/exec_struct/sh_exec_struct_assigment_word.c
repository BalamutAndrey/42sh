/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_assigment_word.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:41:19 by eboris            #+#    #+#             */
/*   Updated: 2020/12/13 15:14:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

u_int64_t	sh_exec_struct_write_assigmentword_num(t_main *main)
{
	t_node		*temp;
	u_int64_t	n;

	temp = main->tree_curr;
	n = 0;
	while (temp != NULL)
	{
		if (temp->node_type == ASSIGNMENT_WORD)
		{
			n++;
		}
		temp = temp->right;
	}
	if (n > 0)
		return (n + 1);
	return (0);
}

void		sh_exec_struct_write_assigmentword(t_main *main)
{
	t_node		*temp;
	u_int64_t	n;
	u_int64_t	i;
	char		**vars;

	temp = main->tree_curr;
	n = sh_exec_struct_write_assigmentword_num(main);
	i = 0;
	if (n != 0)
	{
		vars = malloc(sizeof(char*) * n);
		while (temp != NULL)
		{
			if (temp->token->type == ASSIGNMENT_WORD)
			{
				sh_exec_struct_write_assigmentword_add(temp, vars, &i);
			}
			temp = temp->right;
		}
		vars[i] = NULL;
		main->exec_curr->vars = vars;
	}
}

void		sh_exec_struct_write_assigmentword_add(t_node *temp,
			char **vars, u_int64_t *i)
{
	u_int64_t	n;

	n = *i;
	vars[n] = ft_strdup(temp->token->content);
	n++;
	*i = n;
}
