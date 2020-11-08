/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:57:04 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 16:33:30 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_REMOVE_H
# define SH_REMOVE_H

/*
** sh_remove_struct.c
*/
void	sh_remove_struct(t_main **main);
void	sh_remove_struct_string(t_main *temp);

/*
** sh_remove_envp_curr.c
*/
void	sh_remove_envp_curr(t_main *main);

/*
** sh_remove_path.c
*/
void	sh_remove_path(t_main *main);

/*
** sh_remove_hist.c
*/
void	sh_remove_hist(t_main *main);

/*
** sh_remove_heredoc.c
*/
void	sh_remove_heredoc(t_main *main);

/*
** sh_remove_token.c
*/
void	sh_remove_token(t_main *main);
void	sh_remove_token_lists(t_main *main);

/*
** sh_remove_tree.c
*/
void	sh_remove_tree(t_main *main);
void	sh_remove_node(t_node *node);

/*
** sh_remove_exec.c
*/
void	sh_remove_exec(t_main *main);
void	sh_remove_argv(char **argv);
void	sh_remove_exec_exec(t_exec *temp);
void	sh_remove_redirect(t_redirect *redir);

/*
** sh_remove_fds.c
*/
void	sh_remove_fds(t_main *main);

/*
** sh_remove_envvar.c
*/
void	sh_remove_envvar(t_envvar *envvar);

#endif
