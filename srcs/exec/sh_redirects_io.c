/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects_io.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:07:16 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 19:07:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_redirect_get_second_io(char *str)
{
	int		i;
	int		ret;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	ret = ft_atoi(str);
	return (ret);
}

void	sh_redirect_to_ionumber(t_redirect *new)
{
	int		fd;

	if (ft_strcmp("-", new->filename) == 0)
		close(new->io_num);
	else if ((ft_isdigit(new->filename[0]) == 1) &&
		((fd = sh_redirect_get_second_io(new->filename)) != -1))
	{
		if (fd > 2)
		{
			new->error = -5;
			sh_redirect_error_print(new);
		}
		dup2(fd, new->io_num);
	}
	else
	{
		new->error = -6;
		sh_redirect_error_print(new);
	}
}

void	sh_redirect_from_ionumber(t_redirect *new)
{
	int		fd;

	if (ft_strcmp("-", new->filename) == 0)
		close(new->io_num);
	else if ((ft_isdigit(new->filename[0]) == 1) &&
		((fd = sh_redirect_get_second_io(new->filename)) != -1))
	{
		if (fd > 2)
		{
			new->error = -5;
			sh_redirect_error_print(new);
		}
		dup2(fd, new->io_num);
	}
	else
	{
		new->error = -6;
		sh_redirect_error_print(new);
	}
}
