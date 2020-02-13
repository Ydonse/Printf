/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:20:25 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:57:21 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_precision(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = nb < 0 ? list->nb_size - 1 : list->nb_size;
	if (list->dot == 1 && list->dot_size > j && list->type_entree == number)
	{
		if (nb < 0)
		{
			str[i++] = '-';
			list->type_str++;
		}
		while (j < list->dot_size)
		{
			str[i++] = '0';
			j++;
		}
	}
	return (i);
}

int	check_negative_precision(t_plist *list, int i, char *str)
{
	int j;

	j = list->nb_size;
	if (list->dot == 1 && list->dot_size < 0)
	{
		while (j < ft_abs(list->dot_size))
		{
			str[i++] = ' ';
			j++;
		}
	}
	return (i);
}
