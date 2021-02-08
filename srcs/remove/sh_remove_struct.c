/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:51:52 by eboris            #+#    #+#             */
/*   Updated: 2021/02/09 00:42:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_struct(t_main **main)
{
	t_main	*temp;

	temp = *main;
	sh_remove_struct_string(temp);
	sh_remove_envp_curr(temp);
	sh_remove_path(temp);
	sh_remove_hist(temp);
	sh_remove_heredoc(temp);
	sh_remove_token(temp);
	sh_remove_tree(temp);
	sh_remove_exec(temp);
	sh_remove_fds(temp);
	sh_remove_vars(temp);
	sh_remove_alias(temp);
	sh_remove_jobs(temp);
	free(*main);
	*main = NULL;
	main = NULL;
	temp = NULL;
}

void	sh_remove_struct_string(t_main *temp)
{
	if (temp->term_name != NULL)
		ft_strdel(&temp->term_name);
	if (temp->user != NULL)
		ft_strdel(&temp->user);
	if (temp->home != NULL)
		ft_strdel(&temp->home);
	if (temp->dir != NULL)
		ft_strdel(&temp->dir);
	if (temp->ks != NULL)
		ft_strdel(&temp->ks);
	if (temp->ks_temp != NULL)
		ft_strdel(&temp->ks_temp);
	if (temp->cursor_sel_text != NULL)
		ft_strdel(&temp->cursor_sel_text);
	if (temp->prompt != NULL)
		ft_strdel(&temp->prompt);
}
