/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:00 by geliz             #+#    #+#             */
/*   Updated: 2021/01/08 13:54:34 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

/*
** sh_exec.c
*/
void	sh_exec(t_main *main, t_exec *exec);
void	sh_standart_exec(t_exec *exec, t_main *main);
int16_t	sh_exec_prog(t_exec *exec, t_main *main, char *err_built);
void	sh_exec_print_error(int16_t error, t_main *main);

/*
** sh_redirects_hub.c
*/
int		sh_redirects_hub(t_exec *exec, t_main *main);
void	sh_set_default_io_value(t_main *main);
void	sh_redirect_from_heredoc(t_redirect *new);
void	sh_add_opened_fd(t_main *main, int nbr);

/*
** sh_redirects.c
*/
void	sh_redirect_from_file(t_redirect *new, t_main *main);
void	sh_redirect_to_file_append(t_redirect *new, t_main *main);
void	sh_redirect_to_file(t_redirect *new, t_main *main);
/*
** sh_redirects_io.c
*/
void	sh_redirect_from_ionumber(t_redirect *new);
void	sh_redirect_to_ionumber(t_redirect *new);
int		sh_redirect_get_second_io(char *str);
/*
** sh_redirect_check_chmod.c
*/
void	sh_redirect_check_chmod(t_main *main, t_redirect *new);
void	sh_redirect_error_print(t_redirect *new);
void	sh_redirect_error_dir_check(char *dir, t_redirect *new);
void	sh_redirect_error_file_check(char *str, t_redirect *new);
char	*sh_redirect_error_find_dir(t_main *main, t_redirect *new);
/*
** sh_exec_check_vars.c
*/
void	sh_add_var_to_struct(t_main *main, char *str, int type);
void	sh_get_vars_from_env(t_main *main);
void	sh_check_variables(t_exec *exec, t_main *main);
int		sh_check_exist_var(t_main *main, char *str);
void	sh_change_current_env(t_main *main, t_vars *vars);
/*
** sh_exec_pipes.c
*/
void	sh_exec_piped_commands(t_exec *exec, t_main *main);
void	fill_pipe(int fd[2], int str_fd[2]);
void	sh_stdout_pipe(t_exec *exec, int fd[2], t_main *main);
void	sh_stdin_pipe(t_exec *exec, int fd[2], t_main *main);
void	sh_std_in_out_pipe(t_exec *exec, int fd[2], int fd2[2], t_main *main);
/*
** sh_access_file.c
*/
int		sh_run_access(char **str);
bool	sh_is_builtin(char *str);
bool	sh_is_builtin_nofork(char *str);

/*
** sh_path_add.c
*/
void	sh_path_add(t_main *main, t_exec *temp);
void	sh_run_write_string_point(t_main *main, t_exec *temp);
void	sh_run_write_string_home(t_main *main, t_exec *temp);
void	sh_find_path(t_main *main, t_exec *exec);
/*
** sh_envvar_in_exec.c
*/
char	*sh_find_envvar_in_vars(t_main *main, t_envvar *envvar);
void	sh_change_envvars_in_exec(t_main *main, t_exec *exec);
void	sh_envvar_change_argv(t_envvar *envvar, t_exec *exec, char *new_str);
char	*sh_change_envvars_in_exec_struct(t_main *main, t_envvar *envvar);
/*
** sh_envvar_in_redirs.c
*/
void	sh_change_envvars_in_redirs(t_main *main, t_redirect *redir);
void	sh_envvar_change_redir_cont(t_redirect *redir, char *new_str);
char	*sh_change_envvars_in_redir_struct(t_main *main, t_envvar *envvar);
/*
** sh_envvar_func.c
*/
char	*sh_find_envvar_in_env(char **env, t_envvar *envvar, t_main *main);
char	*sh_get_envvar_from_str(t_envvar *envvar, t_main *main);
void	sh_envvar_add_shift_to_struct(t_envvar *envvar, char *new_str,
	int shift);
/*
** sh_access_file.c
*/
char	*sh_exec_builtin(t_exec *exec, t_main *main);
/*
** sh_envvar_conditions.c
*/

#endif
