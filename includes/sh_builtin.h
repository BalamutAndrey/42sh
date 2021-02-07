/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:20:13 by eboris            #+#    #+#             */
/*   Updated: 2021/02/07 17:54:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTIN_H
# define SH_BUILTIN_H

/*
** For type
*/
typedef	struct			s_btype
{
	bool				a;
	bool				f;
	bool				p;
	bool				t;
	bool				big_p;
	char				**cmd;
	char				**fin;
}						t_btype;

/*
** sh_type.c
*/
void	sh_type(t_exec *exec, t_main *main);
t_btype	*sh_type_create_struct(t_main *main);
void	sh_type_remove_struct(t_btype **new);
void	sh_type_write_struct(t_btype new, t_exec *exec, t_main *main);
void	sh_type_check_cmd(t_main *main, t_btype *new);

/*
** sh_type_args.c
*/
bool	sh_type_read_args(t_exec *exec, t_btype *new, t_main *main);
void	sh_type_args_usage(void);

/*
** sh_type_args_keys.c
*/
bool	sh_type_args_keys(t_btype *new, char *str);
bool	sh_type_args_key_check(t_btype *new, char c);
bool	sh_type_args_key_check_other(t_btype *new, char c);

/*
** sh_type_args_cmds.c
*/
bool	sh_type_args_cmds(t_btype *new, char **argv, int i, t_main *main);
void	sh_type_args_cmds_write(t_btype *new, char **argv, int i, t_main *main);
void	sh_type_args_fin_write(t_btype *new, int n, t_main *main);

/*
** sh_type_check_cmd.c
*/
void	sh_type_check_f(t_main *main, t_btype *new, int i);
void	sh_type_check_p(t_main *main, t_btype *new, int i);
void	sh_type_check_t(t_main *main, t_btype *new, int i);
void	sh_type_check_bigp(t_main *main, t_btype *new, int i);
void	sh_type_check_a(t_main *main, t_btype *new, int i);

/*
** sh_cd.c
*/
char	*sh_cd(t_exec *exec, t_main *main);
char	*sh_cd_check_param(t_exec *exec, t_main *main);
char	*sh_cd_change_dir(t_exec *exec, t_main *main, bool param);
void	sh_chdir_save_argv(t_exec *exec, t_main *main, int8_t p);
void	sh_cd_no_args(t_exec *exec, t_main *main);
/*
** sh_cd_fin.c
*/
char	*sh_chdir_finish(t_exec *exec, t_main *main, bool param, int8_t p);
void	sh_chdir_and_env(t_main *main, t_exec *exec, bool param, int8_t p);
/*
** sh_cd_path.c
*/
void	sh_home_dir(t_exec *exec, t_main *main, int p);
void	sh_prev_dir(t_exec *exec, t_main *main, int p);
void	sh_no_root_dir(t_exec *exec, t_main *main, int p);

/*
** sh_env_replace.c
*/
int		sh_env_replace(t_main *new, char *whats, char *to);
void	sh_env_replace_new(t_main *new, char *whats, char *to);
void	sh_env_remove(t_main *new);
int		sh_env_len(t_main *new);

/*
** sh_pwd.c
*/
void	sh_pwd(t_exec *exec, t_main *main);
void	sh_pwd_error(t_main *main);
void	sh_pwd_check_param(t_exec *exec, t_main *main);
void	sh_pwd_print_dir(t_main *main, bool param);

/*
** sh_exit.c
*/
void	sh_exit(t_exec *exec, t_main *main);
void	sh_exit_error(t_main *main);

/*
** sh_echo.c
*/
void	sh_builtin_echo(t_main *main, t_exec *exec);
int		sh_echo_with_changes(char **str, int j, int flags[2], t_main *main);
int		sh_echo_get_flags(char **argv, int flags[2]);
/*
** sh_echo_spec_symb.c
*/
int		sh_echo_is_spec(char *str, int i, t_main *main);
int		sh_check_octal_nbr(char *str, int i, t_main *main);
int		sh_is_octal_nbr(char c);
void	sh_print_spec(char c);
/*
** sh_builtin_env.c
*/
void	sh_builtin_env(t_main *main);
/*
** sh_builtin_setenv.c
*/
char	*sh_builtin_setenv(t_exec *exec, t_main *main);
char	*sh_builtin_setenv_env_find(t_exec *exec, t_main *main);
void	sh_builtin_setenv_new_env(t_exec *exec, t_main *main, char *tmp, int i);
void	sh_builtin_setenv_change_env(t_exec *exec, t_main *main, char *tmp,
		int i);
/*
** sh_builtin_unsetenv.c
*/
char	*sh_builtin_unsetenv(t_exec *exec, t_main *main);
void	sh_builtin_unsetenv_delete_one(t_main *main, char *tmp);
void	sh_builtin_unsetenv_create_new(t_main *main, int pos, int j);

/*
** sh_alias.c
*/
char	*sh_alias(t_exec *exec, t_main *main);

/*
** sh_alias_print.c
*/
void	sh_alias_print(t_main *main);
void	sh_alias_print_one(t_main *main, char *name);

/*
** sh_alias_arg.c 
*/
char	*sh_alias_arg(t_exec *exec, t_main *main);
void	sh_alias_new(t_main *main, char *str);
void	sh_alias_replace(t_main *main, char *str);
/*
** sh_builtin_set.c 
*/
void	sh_builtin_set(t_main *main);

/*
** sh_builtin_unset.c 
*/
void	sh_builtin_unset(t_exec *exec, t_main *main);

/*
** sh_builtin_export.c 
*/
void	sh_builtin_export(t_exec *exec, t_main *main);

/*
** sh_unalias.c
*/
char	*sh_builtin_unalias(t_exec *exec, t_main *main);

/*
** sh_builtin_jobs.c
*/
void	sh_builtin_jobs(t_exec *exec, t_main *main);

/*
** sh_builtin_fg.c
*/
void	sh_builtin_fg(t_exec *exec, t_main *main);

#endif
