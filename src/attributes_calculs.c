/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_calculs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:42:22 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:57:12 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_attributes_length(t_plist *list, int i)
{
	int n_size;

	n_size = ft_strlen(list->type_str);
	if (list->sharp)
		i += 2;
	if (list->plus == 1 || list->space == 1)
		i += 1;
	if (list->dot)
		i += ft_abs(list->dot_size);
	if (list->min_w > 0)
	{
		i += list->min_w;
	}
	return (i);
}

int		check_if_copy(t_plist *list, long double nb, int i, char *str)
{
	int size;

	size = ft_strlen(list->type_str);
	if (!(list->dot && !list->dot_size && !nb && list->type_entree == number))
	{
		if (list->type_entree == character && list->dot &&
			list->dot_size < size && list->string)
		{
			ft_strncpy(&str[i], list->type_str, list->dot_size);
			str[i + list->dot_size] = '\0';
			i += list->dot_size;
		}
		else
		{
			if (list->zero && nb < 0)
			{
				list->type_str++;
				size--;
			}
			ft_strcpy(&str[i], list->type_str);
			i += size;
			str[i] = '\0';
		}
	}
	return (i);
}

int		check_normal_attributes(t_plist *list, long double nb, int i, char *str)
{
	if (list->dot && list->type_entree == number)
		list->zero = 0;
	i = check_sharp_hexa_minus(list, nb, 0, str);
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	i = check_sharp_hexa_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = check_precision(list, nb, i, str);
	i = check_sharp_octal(list, nb, i, str);
	i = check_sharp_hexa(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	i = check_field_minus(list, nb, i, str);
	i = check_negative_precision(list, i, str);
	return (i);
}

int		check_float_attributes(t_plist *list, long double nb, int i, char *str)
{
	i = 0;
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	i = check_field_minus(list, nb, i, str);
	return (i);
}

char	*add_attributes(t_plist *list, long double nb)
{
	char	*str;
	int		i;
	int		attribute_size;
	char	**save;

	if (!(save = (char**)malloc(sizeof(char*))))
		return (NULL);
	save[0] = list->type_str;
	list->nb_size = ft_strlen(list->type_str);
	attribute_size = get_attributes_length(list, 0);
	if (!(str = (char *)malloc(sizeof(char) * list->nb_size
		+ attribute_size + 1)))
		return (NULL);
	ft_bzero(str, list->nb_size + attribute_size + 1);
	if (list->f_type)
		i = check_float_attributes(list, nb, 0, str);
	else
		i = check_normal_attributes(list, nb, 0, str);
	ft_strdel(save);
	free(save);
	return (str);
}
