/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:26:51 by eboris            #+#    #+#             */
/*   Updated: 2020/11/29 15:59:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCTS_H
# define SH_STRUCTS_H

# define MAX_KS_LEN		1024
# define MAX_DIR_LEN	1024

typedef enum			e_type {
	NONE,
	COMPLETE_COMMAND,
	LIST,
	PIPELINE,
	AND_OR,
	COMMAND,
	CMDNAME,
	CMDSUFFIX,
	SEPARATOR,

	WORD,
	NEWLINE,
	IO_NUMBER,
	LESS,
	GREAT,
	AND_IF,
	OR_IF,
	DSEMI,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSGREAT,
	DLESSDASH,
	CLOBBER,
	LBRACE,
	RBRACE,
	BANG
}						t_type;

typedef	struct			s_fds {
	int					nbr;
	struct s_fds		*next;
}						t_fds;

typedef struct			s_heredoc {
	char				*delim;
	char				*content;
	int					delim_start;
	int					here_start;
	int					here_end;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct			s_path
{
	char				*path;
	struct s_path		*next;
}						t_path;

typedef struct			s_hist
{
	char				*com;
	struct s_hist		*next;
	struct s_hist		*prev;
}						t_hist;

typedef struct			s_envvar
{
	int					start;
	int					end;
	int					type;
	char				*str;
	struct s_envvar		*next;
}						t_envvar;

typedef struct			s_token {
	t_type				type;
	char				*content;
	t_envvar			*envvar;
	struct s_token		*next;
}						t_token;

typedef struct			s_token_free
{
	t_token				*token;
	struct s_token_free	*next;
}						t_token_free;

typedef struct			s_node {
	t_type				node_type;
	t_token				*token;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

typedef struct			s_redirect {
	int					io_num;
	t_type				type;
	char				*filename;
	t_envvar			*envvar;
	t_envvar			*envvar_first;
	t_envvar			*envvar_curr;
	int					error;
	struct s_redirect	*next;
}						t_redirect;

typedef struct			s_exec {
	char				*cmd;
	char				**argv;
	t_redirect			*redir;
	bool				pipe;
	int					pipefd[2];
	t_envvar			*envvar;
	t_envvar			*envvar_first;
	t_envvar			*envvar_curr;
	struct s_exec		*next;
}						t_exec;

typedef struct 			s_alias {
	char				*name;
	char				*command;
	struct s_alias		*next;
}						t_alias;

typedef struct			s_main
{
	char				*term_name;
	int64_t				fd;
	uint64_t			term_col;
	uint64_t			term_row;
	struct termios		t_start;
	struct termios		t_curr;
	char				**envp;
	char				**envp_curr;
	t_path				*path;
	t_hist				*hist;
	t_hist				*hist_curr;
	t_hist				*hist_end;
	char				*user;
	char				*home;
	char				*dir;
	char				*ks;
	char				*ks_temp;
	uint64_t			ks_len;
	uint64_t			ks_temp_len;
	uint64_t			cursor;
	uint64_t			cursor_line;
	uint64_t			cursor_curr;
	uint64_t			cursor_line_curr;
	bool				cursor_sel;
	uint64_t			cursor_sel_start;
	uint64_t			cursor_sel_end;
	char				*cursor_sel_text;
	uint64_t			curs[MAX_KS_LEN];
	char				*prompt;
	uint64_t			prompt_len;
	t_heredoc			*heredoc;
	t_token				*token;
	t_token				*token_curr;
	t_token_free		*token_first;
	t_alias				*alias;
	t_alias				*alias_end;
	t_node				*tree_first;
	t_node				*tree_curr;
	t_exec				*exec_first;
	t_exec				*exec_curr;
	int32_t				cpid;
	t_fds				*opfds;
}						t_main;

/*
** sh_structs.c
*/
t_main					*sh_add_main_struct(char **env);
void					sh_copy_envp(t_main *main);
void					sh_write_struct(t_main *new);
void					sh_remove_struct(t_main **main);

/*
** sh_path.c
*/
void					sh_path(t_main *main);
void					sh_path_del(t_main *main);
t_path					*sh_path_write(char *param, t_main *main);
char					*sh_path_check_param(char *param, int i);
t_path					*sh_path_write_struct(t_path *prev, t_path **first,
						char *str, t_main *main);

#endif
