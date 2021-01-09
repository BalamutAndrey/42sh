NAME=42sh

CC=gcc
FLAGS=-g -Wall -Wextra -Werror

SRC_DIR=./srcs
RL_DIR=./srcs/read
RL_KEY_DIR=./srcs/read/keys
ERR_DIR=./srcs/errors
PS_DIR=./srcs/lexer/parser
LX_DIR=./srcs/lexer
TREE_DIR=./srcs/lexer/tree
ES_DIR=./srcs/lexer/exec_struct
EX_DIR=./srcs/exec
EX_BN_DIR=./srcs/exec/builtin
FC_DIR=./srcs/func
RM_DIR=./srcs/remove
SG_DIR=./srcs/signal
STRUCT_DIR=./srcs/structs
TERM_DIR=./srcs/term
OBJ_DIR=./obj
LIB_DIR=./libft

SRC_NAME=sh_main.c
RL_NAME=sh_cursor.c \
		sh_cursor_math.c \
		sh_history.c \
		sh_history_read.c \
		sh_isprint.c \
		sh_readline.c \
		sh_readline_end.c \
		sh_readline_readkey.c
RL_KEY_NAME=sh_key_backspace.c \
		sh_key_ctrl_d.c \
		sh_key_ctrl_left.c \
		sh_key_ctrl_right.c \
		sh_key_delete.c \
		sh_key_down.c \
		sh_key_end.c \
		sh_key_enter.c \
		sh_key_home.c \
		sh_key_left.c \
		sh_key_opt_a.c \
		sh_key_opt_c.c \
		sh_key_opt_q.c \
		sh_key_opt_v.c \
		sh_key_opt_x.c \
		sh_key_right.c \
		sh_key_shift_left.c \
		sh_key_shift_right.c \
		sh_key_up.c \
		sh_keys.c
ERR_NAME=sh_term_errors.c 
PS_NAME=sh_parser.c \
		sh_parser_check_quotes.c \
		sh_parser_heredoc.c \
		sh_parser_heredoc_delim_correction.c \
		sh_parser_heredoc_quotes_rm.c \
		sh_parser_heredoc_struct.c \
		sh_parser_pipe.c \
		sh_parser_slash.c
LX_NAME=sh_add_heredoc_content.c \
		sh_add_operator_token.c \
		sh_check_and_add_token.c \
		sh_envvar_struct.c \
		sh_is_operator.c \
		sh_lexer.c \
		sh_lexer_find_quotes.c \
		sh_quote_remove.c \
		sh_quote_remove_funcs.c \
		sh_token_quote_remove.c \
		sh_token_struct.c \
		sh_lexer_alias_check.c
TREE_NAME=sh_and_or.c \
		sh_brace_group.c \
		sh_case_clause.c \
		sh_case_item.c \
		sh_case_item_ns.c \
		sh_case_list.c \
		sh_case_list_ns.c \
		sh_cmd_name.c \
		sh_cmd_prefix.c \
		sh_cmd_prefix_assigment_word.c \
		sh_cmd_suffix.c \
		sh_cmd_word.c \
		sh_command.c \
		sh_complete_command.c \
		sh_compound_command.c \
		sh_compound_command_clause.c \
		sh_compound_list.c \
		sh_do_group.c \
		sh_else_part.c \
		sh_filename.c \
		sh_fname.c \
		sh_for_clause.c \
		sh_function_body.c \
		sh_function_definition.c \
		sh_here_end.c \
		sh_if_clause.c \
		sh_in.c \
		sh_io_file.c \
		sh_io_file_greats.c \
		sh_io_here.c \
		sh_io_redirect.c \
		sh_io_redirect_command.c \
		sh_lexer_func.c \
		sh_lexer_tree.c \
		sh_lexer_tree_error.c \
		sh_linebreak.c \
		sh_list.c \
		sh_name.c \
		sh_newline_list.c \
		sh_pattern.c \
		sh_pipe_sequence.c \
		sh_pipeline.c \
		sh_redirect_list.c \
		sh_separator.c \
		sh_separator_op.c \
		sh_sequential_sep.c \
		sh_simple_command.c \
		sh_simple_command_command.c \
		sh_subshell.c \
		sh_term.c \
		sh_until_clause.c \
		sh_while_clause.c \
		sh_wordlist.c
ES_NAME=sh_exec_struct_argv.c \
		sh_exec_struct_create.c \
		sh_exec_struct_create_go.c \
		sh_exec_struct_new.c \
		sh_exec_struct_redirect.c \
		sh_exec_struct_assigment_word.c \
		sh_exec_struct_envvar.c
EX_NAME=sh_access_file.c \
		sh_envvar_func.c \
		sh_envvar_in_exec.c \
		sh_envvar_in_redirs.c \
		sh_exec.c \
		sh_exec_builtin.c \
		sh_exec_pipes.c \
		sh_path_add.c \
		sh_redirect_check_chmod.c \
		sh_exec_check_vars.c \
		sh_redirects.c \
		sh_redirects_hub.c \
		sh_redirects_io.c
EX_BN_NAME=sh_cd.c \
		sh_alias.c \
		sh_alias_arg.c \
		sh_alias_print.c \
		sh_cd_fin.c \
		sh_cd_path.c \
		sh_echo.c \
		sh_echo_spec_symb.c \
		sh_env_replace.c \
		sh_exit.c \
		sh_pwd.c \
		sh_type.c \
		sh_type_args.c \
		sh_builtin_env.c \
		sh_builtin_setenv.c \
		sh_builtin_unsetenv.c \
		sh_builtin_set.c \
		sh_builtin_unset.c \
		sh_builtin_export.c
FC_NAME=sh_malloc_func.c \
		sh_strjoin_func.c \
		sh_strs.c
RM_NAME=sh_remove_envp_curr.c \
		sh_remove_exec.c \
		sh_remove_fds.c \
		sh_remove_heredoc.c \
		sh_remove_hist.c \
		sh_remove_path.c \
		sh_remove_struct.c \
		sh_remove_token.c \
		sh_remove_tree.c \
		sh_remove_envvar.c \
		sh_remove_alias.c
SG_NAME=sh_ctrl_c.c \
		sh_screen_resize.c \
		sh_signal.c
STRUCT_NAME=sh_path.c \
		sh_structs.c
TERM_NAME=sh_term_check_errors_start.c \
		sh_term_init.c

SRC = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))
RL = $(addprefix $(OBJ_DIR)/, $(RL_NAME:.c=.o))
RL_KEY = $(addprefix $(OBJ_DIR)/, $(RL_KEY_NAME:.c=.o))
ERR = $(addprefix $(OBJ_DIR)/, $(ERR_NAME:.c=.o))
PS = $(addprefix $(OBJ_DIR)/, $(PS_NAME:.c=.o))
LX = $(addprefix $(OBJ_DIR)/, $(LX_NAME:.c=.o))
TREE = $(addprefix $(OBJ_DIR)/, $(TREE_NAME:.c=.o))
ES = $(addprefix $(OBJ_DIR)/, $(ES_NAME:.c=.o))
EX = $(addprefix $(OBJ_DIR)/, $(EX_NAME:.c=.o))
EX_BN = $(addprefix $(OBJ_DIR)/, $(EX_BN_NAME:.c=.o))
FC = $(addprefix $(OBJ_DIR)/, $(FC_NAME:.c=.o))
RM = $(addprefix $(OBJ_DIR)/, $(RM_NAME:.c=.o))
SG = $(addprefix $(OBJ_DIR)/, $(SG_NAME:.c=.o))
STRUCT = $(addprefix $(OBJ_DIR)/, $(STRUCT_NAME:.c=.o))
TERM = $(addprefix $(OBJ_DIR)/, $(TERM_NAME:.c=.o))

OBJ = $(SRC) $(RL) $(RL_KEY) $(ERR) $(PS) $(LX) $(TREE) $(ES) $(EX) $(EX_BN) $(FC) $(RM) $(SG) $(STRUCT) $(TERM) 
INC = -I ./includes -I $(LIB_DIR)/includes

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB_DIR)
	@$(CC) -o $(NAME) $(SRC) $(RL) $(RL_KEY) $(ERR) $(PS) $(LX) $(TREE) $(ES) $(EX) $(EX_BN) $(FC) $(RM) $(SG) $(STRUCT) $(TERM) \
		$(LIB_DIR)/libft.a -lncurses -ltermcap $(INC) $(FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(RL_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(RL_KEY_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(ERR_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(PS_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(LX_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(TREE_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(ES_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(EX_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(EX_BN_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(FC_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(RM_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(STRUCT_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(TERM_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

$(OBJ_DIR)/%.o: $(SG_DIR)/%.c
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

clean:
		@make clean -s -C $(LIB_DIR)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -s -C $(LIB_DIR)
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
