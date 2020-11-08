/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:57:23 by eboris            #+#    #+#             */
/*   Updated: 2020/10/28 17:58:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_MAIN_H
# define SH_MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdint.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include "sh_structs.h"
# include "sh_remove.h"
# include "sh_errors.h"
# include "sh_keys.h"
# include "sh_signal.h"
# include "sh_func.h"
# include "sh_read.h"
# include "sh_signal.h"
# include "sh_term.h"
# include "sh_parser.h"
# include "sh_lexer.h"
# include "sh_lexer_tree.h"
# include "sh_lexer_exec.h"
# include "sh_exec.h"
# include "sh_builtin.h"

#endif
