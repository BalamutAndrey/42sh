/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:34:32 by eboris            #+#    #+#             */
/*   Updated: 2020/10/25 19:01:03 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_FUNC_H
# define SH_FUNC_H

/*
** sh_read_ks.c
*/
char	*ft_strmbncpy(char *src, int i);
char	*ft_strmancpy(char *src, int i);
char	*ft_strsdup(char *b, char *a);
/*
** sh_malloc_func.c
*/
char	*sh_strnew(size_t size, t_main *main);
char	*sh_strsub(const char *s, unsigned int start, size_t len, t_main *main);
char	*sh_strdup(const char *src, t_main *main);
void	*sh_memalloc(size_t size, t_main *main);
/*
** sh_strjoin_func.c
*/
char	*sh_strjoin(char const *s1, char const *s2, t_main *main);
char	*sh_check_str_value_strjoin_arg(char *ret, char *temp, t_main *main);
char	*sh_strjoin_arg(t_main *main, const char *s, ...);

#endif
