/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:38:39 by eboris            #+#    #+#             */
/*   Updated: 2020/12/10 17:52:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_exec	*sh_exec_struct_new(t_main *main)
{
	t_exec	*new;

	new = sh_memalloc(sizeof(t_exec), main);
	new->argv = NULL;
	new->redir = NULL;
	new->pipe = false;
	new->andif = false;
	new->pipefd[0] = STDIN_FILENO;
	new->pipefd[1] = STDOUT_FILENO;
	new->envvar = NULL;
	new->envvar_first = NULL;
	new->envvar_curr = NULL;
	new->vars = NULL;
	new->next = NULL;
	return (new);
}
