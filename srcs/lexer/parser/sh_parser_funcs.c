#include "sh_main.h"

int		sh_is_it_protected(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	while (i > 0 && str[i - 1] == '\\')
	{
		i--;
		j++;
	}
	if (j % 2 == 0)
		return (0);
	else
		return (1);
}

int		sh_is_str_empty(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		sh_check_fbraces(t_main *main)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = main->ks_res ? main->ks_res : main->ks;
	while (str[i])
	{
		if (str[i] == '{' && sh_is_protected(str, i) == 0)
			count++;
		if (str[i] == '}' && sh_is_protected(str, i) == 0 && count > 0)
			count--;
		i++;
	}
	if (count > 0)
	{
		ft_fprintf(STDERR_FILENO, "42sh: Bad substitution\n");
		return (1);
	}
	return (0);
}

void	sh_alias_recurs_erase(t_main *main)
{
	t_alias	*al;

	al = main->alias;
	while (al)
	{
		al->recurs = 0;
		al = al->next;
	}
}
