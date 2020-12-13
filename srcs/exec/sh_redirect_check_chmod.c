/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect_check_chmod.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:06:19 by geliz             #+#    #+#             */
/*   Updated: 2020/12/13 18:31:34 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_redirect_error_find_dir(t_main *main, t_redirect *new)
{
	int			i;
	char		*ret;

	i = ft_strlen(new->filename);
	while (i != 0 && new->filename[i] != '/')
		i--;
	if (i == 0)
		ret = sh_strdup(main->dir, main);
	else
		ret = sh_strsub(new->filename, 0, i, main);
	return (ret);
}

void	sh_redirect_error_file_check(char *str, t_redirect *new)
{
	struct stat	buff;

	if (new->error == 0 && access(str, F_OK) != 0)
	{
		if (new->type == LESS)
			new->error = -3;
		if (new->type == GREAT || new->type == DGREAT)
			new->error = 1;
	}
	if (new->error == 0)
		lstat(str, &buff);
	if (new->error == 0 && !S_ISLNK(buff.st_mode) && !S_ISREG(buff.st_mode) &&
		!S_ISCHR(buff.st_mode))
		new->error = -4;
	if (new->error == 0 && S_ISLNK(buff.st_mode))
		stat(str, &buff);
	if (new->type == LESS && new->error == 0 && !(buff.st_mode & S_IRUSR) &&
		!(buff.st_mode & S_IRGRP) && !(buff.st_mode & S_IROTH))
		new->error = -2;
	if ((new->type == GREAT || new->type == DGREAT) && new->error == 0 &&
		!(buff.st_mode & S_IWUSR) && !(buff.st_mode & S_IWGRP) &&
		!(buff.st_mode & S_IWOTH))
		new->error = -2;
}

void	sh_redirect_error_dir_check(char *dir, t_redirect *new)
{
	struct stat	buff;

	if (access(dir, F_OK) != 0)
		new->error = -3;
	if (new->error == 0)
		lstat(dir, &buff);
	if (new->error == 0 && !S_ISLNK(buff.st_mode) && !S_ISDIR(buff.st_mode))
		new->error = -1;
	if (new->error == 0 && S_ISLNK(buff.st_mode))
		stat(dir, &buff);
	if (new->error == 0 && !S_ISDIR(buff.st_mode))
		new->error = -1;
	if ((new->type == GREAT || new->type == DGREAT) &&
		!(buff.st_mode & S_IWUSR) && !(buff.st_mode & S_IXUSR) &&
		!(buff.st_mode & S_IWGRP) && !(buff.st_mode & S_IXGRP) &&
		!(buff.st_mode & S_IWOTH) && !(buff.st_mode & S_IXGRP))
		new->error = -2;
}

void	sh_redirect_error_print(t_redirect *new)
{
	if (new->error == -1)
		ft_fprintf(STDERR_FILENO, "21sh: %s: Not a directory\n", new->filename);
	if (new->error == -2)
		ft_fprintf(STDERR_FILENO, "21sh: %s: Permission denied\n",
		new->filename);
	if (new->error == -3)
		ft_fprintf(STDERR_FILENO, "21sh: %s: No such file or directory\n",
		new->filename);
	if (new->error == -4)
		ft_fprintf(STDERR_FILENO, "21sh: %s: Not a file or link\n",
		new->filename);
	if (new->error == -5)
		ft_fprintf(STDERR_FILENO, "21sh: %s: Bad file descriptor\n",
		new->filename);
	if (new->error == -6)
		ft_fprintf(STDERR_FILENO, "21sh: %s: ambiguous redirect\n",
		new->filename);
	exit(0);
}

void	sh_redirect_check_chmod(t_main *main, t_redirect *new)
{
	char	*dir;

	dir = sh_redirect_error_find_dir(main, new);
	sh_redirect_error_dir_check(dir, new);
	ft_strdel(&dir);
	if (new->error >= 0)
		sh_redirect_error_file_check(new->filename, new);
	if (new->error < 0)
	{
		sh_redirect_error_print(new);
	}
}
