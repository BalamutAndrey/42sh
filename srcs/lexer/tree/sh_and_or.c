/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:35:36 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 18:56:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** and_or           :                         pipeline
**                  | and_or AND_IF linebreak pipeline
**                  | and_or OR_IF  linebreak pipeline
*/

t_node	*sh_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_andor_pipeline(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_andor_andor_andif_linebreak_pipeline(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_andor_andor_orif_linebreak_pipeline(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** and_or           :                         pipeline
*/

t_node	*sh_andor_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_pipeline(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** and_or           : and_or AND_IF linebreak pipeline
*/

t_node	*sh_andor_andor_andif_linebreak_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** and_or           : and_or OR_IF  linebreak pipeline
*/

t_node	*sh_andor_andor_orif_linebreak_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}
