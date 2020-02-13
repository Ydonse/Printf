/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_neg_min_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:42:51 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/06 11:18:11 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_char_field_minus(t_plist *list, int i, int j, char *str)
{
	char c;

	c = ' ';
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
	str[i] = '\0';
	return (i);
}

int	fill_nb_field_minus(t_plist *list, int i, int j, char *str)
{
	if (list->dot_size > list->nb_size)
	{
		while (j++ < list->min_w - list->dot_size)
			str[i++] = ' ';
	}
	else
	{
		while (j++ < list->min_w - list->nb_size)
			str[i++] = ' ';
	}
	str[i] = '\0';
	return (i);
}

int	check_nb_field_minus(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = 0;
	if (list->sharp == 1 && list->mode != OCTAL && list->mode && nb != 0)
		j += 2;
	if (list->sharp == 1 && list->mode == OCTAL && list->mode && nb != 0
		&& !(list->dot && list->dot_size > list->nb_size))
		j++;
	if (list->pointer)
		j += 2;
	if ((list->plus == 1 || list->space) && nb >= 0 && list->mode == 0)
		j++;
	if (list->dot && nb < 0 && list->min_w > list->dot_size
		&& list->dot_size > list->nb_size - 1)
		j++;
	i = fill_nb_field_minus(list, i, j, str);
	return (i);
}

int	check_char_field_minus(t_plist *list, int i, char *str)
{
	int j;

	j = 0;
	if (list->type.c == '\0')
		j++;
	if (list->dot && list->dot_size == 0 && !list->string)
		j++;
	i = fill_char_field_minus(list, i, j, str);
	return (i);
}

int	check_field_minus(t_plist *list, long double nb, int i, char *str)
{
	int		j;

	j = 0;
	if (list->min_w > list->nb_size && list->min_w > list->dot_size
	&& list->minus && list->type_entree == number)
		i = check_nb_field_minus(list, nb, i, str);
	if (list->type_entree == character && list->minus)
		i = check_char_field_minus(list, i, str);
	return (i);
}
