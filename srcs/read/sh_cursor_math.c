/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cursor_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:37:04 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 14:11:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_cursor_math(t_main *main)
{
	uint64_t	i;
	uint64_t	l;
	uint64_t	n;

	i = main->prompt_len + 1;
	l = 0;
	n = 0;
	while (main->ks[n] != '\0')
		if (i == (main->term_col))
			sh_cursor_math_if(main, &i, &l, &n);
		else if (main->ks[n] == '\n')
			sh_cursor_math_elseif(main, &i, &l, &n);
		else
			sh_cursor_math_else(&i, &n);
	l++;
	main->curs[l] = i;
	main->curs[l + 1] = 0;
	main->cursor_line = l;
	sh_cursor_math_curr(main);
}

void	sh_cursor_math_if(t_main *main, uint64_t *i, uint64_t *l, uint64_t *n)
{
	*l = *l + 1;
	main->curs[*l] = *i;
	*i = 1;
	*n = *n + 1;
}

void	sh_cursor_math_elseif
	(t_main *main, uint64_t *i, uint64_t *l, uint64_t *n)
{
	uint64_t	temp;

	*l = *l + 1;
	temp = *l;
	main->curs[temp] = *i;
	*i = 1;
	*n = *n + 1;
}

void	sh_cursor_math_else(uint64_t *i, uint64_t *n)
{
	*n = *n + 1;
	*i = *i + 1;
}

void	sh_cursor_math_curr(t_main *main)
{
	uint64_t	i;
	uint64_t	n;

	i = 1;
	n = main->cursor + main->prompt_len + 1;
	while ((n > main->term_col) || (n > main->curs[i]))
	{
		n = n - main->curs[i];
		i++;
	}
	main->cursor_curr = n;
	main->cursor_line_curr = i;
}
