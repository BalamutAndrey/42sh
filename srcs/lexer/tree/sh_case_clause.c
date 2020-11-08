/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_case_clause.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:40:25 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 16:57:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** case_clause      : Case WORD linebreak in linebreak case_list    Esac
**                  | Case WORD linebreak in linebreak case_list_ns Esac
**                  | Case WORD linebreak in linebreak              Esac
*/

t_node	*sh_caseclause(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp =
		sh_caseclause_case_word_linebreak_in_linebreak_caselist_esac(main)) !=
		NULL)
	{
		return (temp);
	}
	else if ((temp =
		sh_caseclause_case_word_linebreak_in_linebreak_caselistns_esac(main)) !=
		NULL)
	{
		return (temp);
	}
	else if ((temp =
		sh_caseclause_case_word_linebreak_in_linebreak_esac(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** case_clause      : Case WORD linebreak in linebreak case_list    Esac
*/

t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselist_esac
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_clause      : Case WORD linebreak in linebreak case_list_ns Esac
*/

t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselistns_esac
	(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** case_clause      : Case WORD linebreak in linebreak              Esac
*/

t_node	*sh_caseclause_case_word_linebreak_in_linebreak_esac(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
