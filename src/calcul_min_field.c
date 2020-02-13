/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_min_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:28:08 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 13:10:55 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_char_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->dot)
	{
		if (list->dot_size >= list->nb_size)
		{
			while (j++ < list->min_w - list->nb_size)
				str[i++] = c;
		}
		if (list->string || (!list->string && list->dot_size >= 0))
		{
			while (j++ < list->min_w - list->dot_size)
				str[i++] = c;
		}
	}
	else if (!list->dot)
	{
		while (j++ < list->min_w - list->nb_size)
			str[i++] = c;
	}
	return (i);
}

int	fill_nb_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->dot_size > list->nb_size)
	{
		while (j++ < list->min_w - list->dot_size)
			str[i++] = c;
	}
	else
	{
		while (j++ < list->min_w - list->nb_size)
			str[i++] = c;
	}
	return (i);
}

int	check_char_field(t_plist *list, int i, char *str)
{
	int j;

	j = 0;
	if (list->type.c == '\0' && !(list->dot && !list->dot_size))
		j++;
	if (list->dot && list->dot_size == 0 && !list->string)
		j++;
	i = fill_char_field(list, i, j, str);
	return (i);
}

int	check_nb_field(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = 0;
	if (list->sharp == 1 && list->mode != OCTAL && list->mode != 0
		&& nb != 0 && !list->pointer)
		j += 2;
	if (list->sharp && list->mode == OCTAL && nb != 0 &&
		!(list->dot && list->dot_size > list->nb_size))
		j++;
	if (list->pointer)
		j += 2;
	if (list->dot && nb < 0 && list->min_w > list->dot_size
		&& list->dot_size > list->nb_size - 1)
		j++;
	if ((list->plus || list->space) && nb >= 0 && list->mode == 0)
		j++;
	if (list->dot && list->min_w > list->dot_size && !list->dot_size && !nb)
		j--;
	i = fill_nb_field(list, i, j, str);
	return (i);
}

int	check_field(t_plist *list, long double nb, int i, char *str)
{
	char	c;

	c = '\0';
	if (list->zero && nb < 0)
		str[i++] = '-';
	if (list->min_w > list->nb_size && list->min_w > list->dot_size
		&& !list->minus && list->dot_size >= 0 && list->type_entree == number)
		i = check_nb_field(list, nb, i, str);
	if (list->type_entree == character && !list->minus)
		i = check_char_field(list, i, str);
	return (i);
}
