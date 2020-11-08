/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_mant_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:45:41 by geliz             #+#    #+#             */
/*   Updated: 2020/01/06 18:07:07 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_array_to_string(char arr[25000])
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (arr[i] != 0)
		i++;
	if (!(ret = ft_strnew(i)))
		return (NULL);
	while (--i > -1)
		ret[j++] = arr[i];
	return (ret);
}

void	ft_summ_strings(char res[25000], char temp[25000])
{
	int		i;
	int		nbr;
	int		ost;

	i = 0;
	ost = 0;
	while (temp[i] != 0 || res[i] != 0)
	{
		if (res[i] == 0 && temp[i] != 0)
			res[i] = '0';
		if (temp[i] != 0)
			nbr = (temp[i] - '0') + (res[i] - '0') + ost;
		else
			nbr = (res[i] - '0') + ost;
		ost = nbr / 10 > 0 ? 1 : 0;
		res[i] = nbr % 10 + '0';
		i++;
		if (res[i] == 0 && ost == 1)
		{
			res[i] = '1';
			ost = 0;
		}
	}
}

void	ft_power_to_two(char temp[25000], int pow)
{
	int		i;
	int		ost;
	int		nbr;

	i = 0;
	while (temp[i] != 0)
		temp[i++] = 0;
	temp[0] = '1';
	ost = 0;
	i = 0;
	while (pow-- > 0)
	{
		while (temp[i] != 0)
		{
			nbr = temp[i] == '0' ? 0 + ost : (temp[i] - '0') * 2 + ost;
			ost = nbr / 10 > 0 ? 1 : 0;
			temp[i++] = nbr % 10 + '0';
		}
		if (temp[i] == 0 && ost == 1)
		{
			temp[i] = '1';
			ost = 0;
		}
		i = 0;
	}
}

void	ft_fill_array_with_zero(char res[25000], char temp[25000])
{
	int			j;

	j = 0;
	while (j < 25000)
	{
		temp[j] = 0;
		res[j] = 0;
		j++;
	}
}

char	*ft_apply_exp_to_mantissa(char *mant, int pow, int sign, t_info *in)
{
	int		j;
	char	*integ;
	char	*divis;
	char	res[25000];
	char	temp[25000];

	ft_fill_array_with_zero(res, temp);
	j = 0;
	while (mant[j] != '\0' && pow >= 0)
	{
		if (mant[j] == '1')
		{
			ft_power_to_two(temp, pow);
			ft_summ_strings(res, temp);
		}
		j++;
		pow--;
	}
	integ = ft_array_to_string(res);
	divis = ft_negative_power_to_mant(mant, j, pow);
	ft_strdel(&mant);
	return (ft_add_divis_to_integ(integ, divis, sign, in));
}
