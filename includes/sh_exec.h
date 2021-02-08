/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:00 by geliz             #+#    #+#             */
/*   Updated: 2021/02/08 23:44:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

enum					e_jobstatus
{
	RUNNING,
	STOPPED,
	SIGNALED,
	ERROR,
	DONE
};

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

/*
** sh_exec_andif_orif_check.c
*/
t_exec	*sh_or_if_and_if_check(t_exec *exec);
t_exec	*sh_andif_check(t_exec *exec);
t_exec	*sh_orif_check(t_exec *exec);
void	sh_exit_code_check(t_exec *exec, int status);

/*
** sh_jobs_funcs.c
*/
void	sh_job_remove(t_jobs *job);
t_jobs	*sh_exec_new_job(pid_t pid, char *cmd, t_main *main);
char	*sh_exec_job_get_cmd(char **argv, t_main *main);
void	sh_exec_jobs_put_signes(t_main *main);
void	sh_exec_setpgid(bool bg, t_main *main);

/*
** sh_jobs_signal_pc.c
*/
void	sh_signal_parrent(t_main *main);
void	sh_signal_child(void);

/*
** sh_jobs_state.c
*/
void	sh_exec_job_state_assign(t_jobs *job, int state, int status);
void	sh_exec_job_state_check(t_jobs *job);
void	sh_exec_job_state(t_jobs *job);
void	sh_jobs_check_not_first(t_jobs *j);
void	sh_exec_job_del_completed(t_main *main);
/*
** sh_jobs.c
*/
void	sh_exec_add_job(t_main *main, t_jobs *job);
void	sh_exec_remove_job(t_main *main, t_jobs *job);
int		sh_exec_find_job(t_main *main, t_jobs *job);
int		sh_exec_wait(t_jobs *job, t_main *main, t_exec *exec);
int		sh_exec_job(t_main *main, t_exec *exec);

/*
** sh_jobs_print.c
*/
void	sh_exec_job_print_completed(t_main *main);


#endif
