/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:20:14 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 17:12:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_TREE_H
# define SH_LEXER_TREE_H

/*
** %start  complete_command
** %%
** complete_command : list separator +
**                  | list			 ++
**                  ;
** list             : list separator_op and_or +
**                  |                   and_or ++
**                  ;
** and_or           :                         pipeline +
**                  | and_or AND_IF linebreak pipeline +
**                  | and_or OR_IF  linebreak pipeline +
**                  ;
** pipeline         :      pipe_sequence +
**                  | Bang pipe_sequence +
**                  ;
** pipe_sequence    :                             command +
**                  | pipe_sequence '|' linebreak command +
**                  ;
** command          : simple_command 				 +
**                  | compound_command				 +
**                  | compound_command redirect_list +
**                  | function_definition			 +
**                  ;
** compound_command : brace_group  +
**                  | subshell	   +
**                  | for_clause   +
**                  | case_clause  +
**                  | if_clause    +
**                  | while_clause +
**                  | until_clause +
**                  ;
** subshell         : '(' compound_list ')' +
**                  ;
** compound_list    :              term			  +
**                  | newline_list term			  +
**                  |              term separator +
**                  | newline_list term separator +
**                  ;
** term             : term separator and_or +
**                  |                and_or +
**                  ;
** for_clause       : For name linebreak                            do_group +
**                  | For name linebreak in          sequential_sep do_group +
**                  | For name linebreak in wordlist sequential_sep do_group +
**                  ;
** name             : NAME                     !! Apply rule 5 !!	+
**                  ;
** in               : In                       !! Apply rule 6 !!	+
**                  ;
** wordlist         : wordlist WORD +
**                  |          WORD +
**                  ;
** case_clause      : Case WORD linebreak in linebreak case_list    Esac +
**                  | Case WORD linebreak in linebreak case_list_ns Esac +
**                  | Case WORD linebreak in linebreak              Esac +
**                  ;
** case_list_ns     : case_list case_item_ns +
**                  |           case_item_ns +
**                  ;
** case_list        : case_list case_item +
**                  |           case_item +
**                  ;
** case_item_ns     :     pattern ')'               linebreak +
**                  |     pattern ')' compound_list linebreak +
**                  | '(' pattern ')'               linebreak +
**                  | '(' pattern ')' compound_list linebreak +
**                  ;
** case_item        :     pattern ')' linebreak     DSEMI linebreak +
**                  |     pattern ')' compound_list DSEMI linebreak +
**                  | '(' pattern ')' linebreak     DSEMI linebreak +
**                  | '(' pattern ')' compound_list DSEMI linebreak +
**                  ;
** pattern          :             WORD         !! Apply rule 4 !!		 +
**                  | pattern '|' WORD         !! Do not apply rule 4 !! +
**                  ;
** if_clause        : If compound_list Then compound_list else_part Fi +
**                  | If compound_list Then compound_list           Fi +
**                  ;
** else_part        : Elif compound_list Then else_part +
**                  | Else compound_list				+
**                  ;
** while_clause     : While compound_list do_group +
**                  ;
** until_clause     : Until compound_list do_group +
**                  ;
** function_definition : fname '(' ')' linebreak function_body +
**                  ;
** function_body    : compound_command                !! Apply rule 9 !! +
**                  | compound_command redirect_list  !! Apply rule 9 !! +
**                  ;
** fname            : NAME                            !! Apply rule 8 !! +
**                  ;
** brace_group      : Lbrace compound_list Rbrace +
**                  ;
** do_group         : Do compound_list Done           !! Apply rule 6 !! +
**                  ;
** simple_command   : cmd_prefix cmd_word cmd_suffix +
**                  | cmd_prefix cmd_word			 +
**                  | cmd_prefix					 +
**                  | cmd_name cmd_suffix			 +
**                  | cmd_name						 +
**                  ;
** cmd_name         : WORD                   !! Apply rule 7a !! ++
**                  ;
** cmd_word         : WORD                   !! Apply rule 7b !! +
**                  ;
** cmd_prefix       :            io_redirect	 +
**                  | cmd_prefix io_redirect	 +
**                  |            ASSIGNMENT_WORD +
**                  | cmd_prefix ASSIGNMENT_WORD +
**                  ;
** cmd_suffix       :            io_redirect +
**                  | cmd_suffix io_redirect +
**                  |            WORD		 +
**                  | cmd_suffix WORD		 +
**                  ;
** redirect_list    :               io_redirect +
**                  | redirect_list io_redirect +
**                  ;
** io_redirect      :           io_file +
**                  | IO_NUMBER io_file +
**                  |           io_here +
**                  | IO_NUMBER io_here +
**                  ;
** io_file          : '<'       filename +
**                  | LESSAND   filename +
**                  | '>'       filename +
**                  | GREATAND  filename +
**                  | DGREAT    filename +
**                  | LESSGREAT filename +
**                  | CLOBBER   filename +
**                  ;
** filename         : WORD                      !! Apply rule 2 !! +
**                  ;
** io_here          : DLESS     here_end +
**                  | DLESSDASH here_end +
**                  ;
** here_end         : WORD                      !! Apply rule 3 !! +
**                  ;
** newline_list     :              NEWLINE +
**                  | newline_list NEWLINE +
**                  ;
** linebreak        : newline_list  +
**                  | !!! empty !!! +
**                  ;
** separator_op     : '&' +
**                  | ';' +
**                  ;
** separator        : separator_op linebreak +
**                  | newline_list			 +
**                  ;
** sequential_sep   : ';' linebreak +
**                  | newline_list  +
**                  ;
*/

/*
** sh_lexer_tree.c
*/
void	sh_lexer_tree_new(t_main *main);
void	sh_lexer_copy_token(t_main *main);

/*
** sh_lexer_func.c
*/
t_node	*sh_lexer_create_node(t_main *main, t_token *token, t_type type);
void	sh_lexer_add_node(t_node *node, t_node *left, t_node *right);
void	sh_lexer_del_node(t_node **node);
void	sh_lexer_del_all_node(t_node **node);

/*
** sh_lexer_tree_error.c
*/
t_node	*sh_lexer_tree_error(t_main *main);

/*
** sh_complete_command.c
*/
t_node	*sh_complete_command(t_main *main, t_node *node);
t_node	*sh_complete_command_list_separator(t_main *main);
t_node	*sh_complete_command_list(t_main *main);
bool	sh_separator_check(t_main *main);

/*
** sh_list.c
*/
t_node	*sh_list(t_main *main);
t_node	*sh_list_separatorop_andor(t_main *main);
t_node	*sh_list_andor(t_main *main);

/*
** sh_and_or.c
*/
t_node	*sh_andor(t_main *main);
t_node	*sh_andor_pipeline(t_main *main);
t_node	*sh_andor_andor_andif_linebreak_pipeline(t_main *main);
t_node	*sh_andor_andor_orif_linebreak_pipeline(t_main *main);

/*
** sh_pipeline.c
*/
t_node	*sh_pipeline(t_main *main);
t_node	*sh_pipeline_pipesequence(t_main *main);
t_node	*sh_pipeline_bang_pipesequence(t_main *main);

/*
** sh_pipe_sequence.c
*/
t_node	*sh_pipesequence(t_main *main);
t_node	*sh_pipesequence_command(t_main *main);
t_node	*sh_pipesequence_pipesequence_pipe_linebreak_command(t_main *main);
void	sh_pipesequence_error(t_main *main, t_node *pipe, t_node *right);

/*
** sh_command.c
*/
t_node	*sh_command(t_main *main);
t_node	*sh_command_simplecommand(t_main *main);
t_node	*sh_command_compoundcommand(t_main *main);
t_node	*sh_command_compoundcommand_redirectlist(t_main *main);
t_node	*sh_command_functiondefinition(t_main *main);

/*
** sh_compound_command.c
*/
t_node	*sh_compoundcommand(t_main *main);
t_node	*sh_compoundcommand_bracegroup(t_main *main);
t_node	*sh_compoundcommand_subshell(t_main *main);

/*
** sh_compound_command_clause.c
*/
t_node	*sh_compoundcommand_forclause(t_main *main);
t_node	*sh_compoundcommand_caseclause(t_main *main);
t_node	*sh_compoundcommand_ifclause(t_main *main);
t_node	*sh_compoundcommand_whileclause(t_main *main);
t_node	*sh_compoundcommand_untilclause(t_main *main);

/*
** sh_subshell.c
*/
t_node	*sh_subshell(t_main *main);
t_node	*sh_subshell_bracket_compoundlist_bracket(t_main *main);

/*
** sh_compound_list.c
*/
t_node	*sh_compoundlist(t_main *main);
t_node	*sh_compoundlist_term(t_main *main);
t_node	*sh_compoundlist_newlinelist_term(t_main *main);
t_node	*sh_compoundlist_term_separator(t_main *main);
t_node	*sh_compoundlist_newlinelist_term_separator(t_main *main);

/*
** sh_term.c
*/
t_node	*sh_term(t_main *main);
t_node	*sh_term_term_separator_andor(t_main *main);
t_node	*sh_term_andor(t_main *main);

/*
** sh_for_clause.c
*/
t_node	*sh_forclause(t_main *main);
t_node	*sh_forclause_for_name_linebreak_dogroup(t_main *main);
t_node	*sh_forclause_for_name_linebreak_in_sequentialsep_dogroup(t_main *main);
t_node	*sh_forclause_for_name_linebreak_in_wordlist_sequentialsep_dogroup
	(t_main *main);

/*
** sh_name.c
*/
t_node	*sh_name(t_main *main);
t_node	*sh_name_name(t_main *main);

/*
** sh_in.c
*/
t_node	*sh_in(t_main *main);
t_node	*sh_in_in(t_main *main);

/*
** sh_wordlist.c
*/
t_node	*sh_wordlist(t_main *main);
t_node	*sh_wordlist_wordlist_word(t_main *main);
t_node	*sh_wordlist_word(t_main *main);

/*
** sh_case_clause.c
*/
t_node	*sh_caseclause(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselist_esac
	(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselistns_esac
	(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_esac(t_main *main);

/*
** sh_case_list_ns.c
*/
t_node	*sh_caselistns(t_main *main);
t_node	*sh_caselistns_caselist_caseitemns(t_main *main);
t_node	*sh_caselistns_caseitemns(t_main *main);

/*
** sh_case_list.c
*/
t_node	*sh_caselist(t_main *main);
t_node	*sh_caselist_caselist_caseitem(t_main *main);
t_node	*sh_caselist_caseitem(t_main *main);

/*
** sh_case_item_ns.c
*/
t_node	*caseitemns(t_main *main);
t_node	*caseitemns_pattern_bracket_linebreak(t_main *main);
t_node	*caseitemns_pattern_bracket_compoundlist_linebreak(t_main *main);
t_node	*caseitemns_bracket_pattern_bracket_linebreak(t_main *main);
t_node	*caseitemns_bracket_pattern_bracket_compoundlist_linebreak
	(t_main *main);

/*
** sh_case_item.c
*/
t_node	*sh_caseitem(t_main *main);
t_node	*sh_caseitem_pattern_bracket_linebreak_dsemi_linebreak(t_main *main);
t_node	*sh_caseitem_pattern_bracket_compoundlist_dsemi_linebreak(t_main *main);
t_node	*sh_caseitem_bracket_pattern_bracket_linebreak_dsemi_linebreak
	(t_main *main);
t_node	*sh_caseitem_bracket_pattern_bracket_compoundlist_dsemi_linebreak
	(t_main *main);

/*
** sh_pattern.c
*/
t_node	*sh_pattern(t_main *main);
t_node	*sh_pattern_word(t_main *main);
t_node	*sh_pattern_pattern_pipe_word(t_main *main);

/*
** sh_if_clause.c
*/
t_node	*sh_ifclause(t_main *main);
t_node	*sh_ifclause_if_compoundlist_then_compoundlist_elsepart_fi
	(t_main *main);
t_node	*sh_ifclause_if_compoundlist_then_compoundlist_fi(t_main *main);

/*
** sh_else_part.c
*/
t_node	*sh_elsepart(t_main *main);
t_node	*sh_elsepart_elif_compoundlist_then_elsepart(t_main *main);
t_node	*sh_elsepart_elif_compoundlist(t_main *main);

/*
** sh_while_clause.c
*/
t_node	*sh_whileclause(t_main *main);
t_node	*sh_whileclause_while_compoundlist_dogroup(t_main *main);

/*
** sh_until_clause.c
*/
t_node	*sh_untilclause(t_main *main);
t_node	*sh_untilclause_until_compoundlist_dogroup(t_main *main);

/*
**sh_function_definition.c
*/
t_node	*sh_functiondefinition(t_main *main);
t_node	*sh_functiondefinition_fname_bracket_bracket_linebreak_functionbody
	(t_main *main);

/*
** sh_function_body.c
*/
t_node	*sh_functionbody(t_main *main);
t_node	*sh_functionbody_compoundcommand(t_main *main);
t_node	*sh_functionbody_compoundcommand_redirectlist(t_main *main);

/*
** sh_fname.c
*/
t_node	*sh_fname(t_main main);
t_node	*sh_fname_name(t_main main);

/*
** sh_brace_group.c
*/
t_node	*sh_bracegroup(t_main *main);
t_node	*sh_bracegroup_lbrace_compoundlist_rbrace(t_main *main);

/*
**	sh_do_group.c
*/
t_node	*sh_dogroup(t_main *main);
t_node	*sh_dogroup_do_compoundlist_done(t_main *main);

/*
** sh_simple_command.c
*/
t_node	*sh_simplecommand(t_main *main);

/*
** sh_simple_command_command.c
*/
t_node	*sh_simplecommand_cmdprefix_cmdword_cmdsuffix(t_main *main);
t_node	*sh_simplecommand_cmdprefix_cmdword(t_main *main);
t_node	*sh_simplecommand_cmdprefix(t_main *main);
t_node	*sh_simplecommand_cmdname_cmdsuffix(t_main *main);
t_node	*sh_simplecommand_cmdname(t_main *main);

/*
** sh_cmd_name.c
*/
t_node	*sh_cmdname(t_main *main);
t_node	*sh_cmdname_word(t_main *main);

/*
** sh_cmd_word.c
*/
t_node	*sh_cmdword(t_main *main);
t_node	*sh_cmdword_word(t_main *main);

/*
** sh_cmd_prefix.c
*/
t_node	*sh_cmdprefix(t_main *main);
t_node	*sh_cmdprefix_ioredirect(t_main *main);
t_node	*sh_cmdprefix_cmdprefix_ioredirect(t_main *main);
t_node	*sh_cmdprefix_assignment_word(t_main *main);
t_node	*sh_cmdprefix_cmdprefix_assignment_word(t_main *main);

/*
** sh_cmd_suffix.c
*/
t_node	*sh_cmdsuffix(t_main *main);
t_node	*sh_cmdsuffix_while(t_main *main, t_node *first, t_node *curr,
	t_node *temp);
t_node	*sh_cmdsuffix_redir(t_main *main, t_node *first, t_node *curr);
t_node	*sh_cmdsuffix_word(t_main *main);
t_node	*sh_cmdsuffix_redir_while(t_main *main, t_node *curr, t_node *temp);

/*
** sh_redirect_list.c
*/
t_node	*sh_redirectlist(t_main *main);
t_node	*sh_redirectlist_ioredirect(t_main *main);
t_node	*sh_redirectlist_redirectlist_ioredirect(t_main *main);
bool	sh_is_a_redirect(t_token *token);

/*
** sh_io_redirect.c
*/
t_node	*sh_ioredirect(t_main *main);
t_node	*sh_ioredirect_while(t_main *main, t_node *first, t_node *curr,
		t_node *temp);

/*
** sh_io_redirect_command.c
*/
t_node	*sh_ioredirect_iofile(t_main *main);
t_node	*sh_ioredirect_ionumber_iofile(t_main *main);
t_node	*sh_ioredirect_iohere(t_main *main);
t_node	*sh_ioredirect_ionumber_iohere(t_main *main);

/*
** sh_io_file.c
*/
t_node	*sh_iofile(t_main *main);
t_node	*sh_iofile_greatleft_filename(t_main *main);
t_node	*sh_iofile_lessand_filename(t_main *main);
t_node	*sh_iofile_greatright_filename(t_main *main);
t_node	*sh_iofile_greatand_filename(t_main *main);

/*
** sh_io_file_greats.c
*/
t_node	*sh_iofile_dgreat_filename(t_main *main);
t_node	*sh_iofile_lessgreat_filename(t_main *main);
t_node	*sh_iofile_clobber_filename(t_main *main);

/*
** sh_filename.c
*/
t_node	*sh_filename(t_main *main);
t_node	*sh_filename_word(t_main *main);

/*
** sh_io_here.c
*/
t_node	*sh_iohere(t_main *main);
t_node	*sh_iohere_dless_hereend(t_main *main);
t_node	*sh_iohere_dlessdash_hereend(t_main *main);

/*
** sh_here_end.c
*/
t_node	*sh_hereend(t_main *main);
t_node	*sh_hereend_word(t_main *main);

/*
** sh_newline_list.c
*/
t_node	*sh_newlinelist(t_main *main);
t_node	*sh_newlinelist_newline(t_main *main);
t_node	*sh_newlinelist_newlinelist_newline(t_main *main);

/*
** sh_linebreak.c
*/
t_node	*sh_linebreak(t_main *main);
t_node	*sh_linebreak_newlinelist(t_main *main);
t_node	*sh_linebreak_empty(t_main *main);

/*
** sh_separator_op.c
*/
t_node	*sh_separatorop(t_main *main);
t_node	*sh_separatorop_ampersand(t_main *main);
t_node	*sh_separatorop_semicolon(t_main *main);

/*
** sh_separator.c
*/
t_node	*sh_separator(t_main *main);
t_node	*sh_separator_separatorop_linebreak(t_main *main);
t_node	*sh_separator_newlinelist(t_main *main);

/*
** sh_sequential_sep.c
*/
t_node	*sh_sequentialsep(t_main *main);
t_node	*sh_sequentialsep_semicolon_linebreak(t_main *main);
t_node	*sh_sequentialsep_newlinelist(t_main *main);

#endif
