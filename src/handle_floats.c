/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:03:48 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/06 11:59:16 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_lf(t_plist *list, va_list *ap, int skip)
{
	list->type.ld = (long double)va_arg(*ap, double);
	list->type_str = ft_ftoa_ld((long double)list->type.ld,
	(((long double)list->type.ld < 0) ? '-' : 0), list);
	list->f_type = 1;
	list->type_str = add_attributes(list, (long double)list->type.ld);
	list->skip += skip;
}

void		handle_maj_lf(t_plist *list, va_list *ap, int skip)
{
	list->type.ld = va_arg(*ap, long double);
	list->type_str = ft_ftoa_ld((long double)list->type.ld,
	(((long double)list->type.ld < 0) ? '-' : 0), list);
	list->f_type = 1;
	list->type_str = add_attributes(list, list->type.ld);
	list->skip += skip;
}

void		handle_f(t_plist *list, va_list *ap, int skip)
{
	list->type.ld = (long double)va_arg(*ap, double);
	list->type_str = ft_ftoa_ld((long double)list->type.ld,
	(((long double)list->type.ld < 0) ? '-' : 0), list);
	list->f_type = 1;
	list->type_str = add_attributes(list, (long double)list->type.ld);
	list->skip += skip;
}

t_sfloat	*init_sfloat(int zap, long long i_part, long double num)
{
	t_sfloat *sfloat;

	if (!(sfloat = (t_sfloat*)malloc(sizeof(t_sfloat))))
		return (NULL);
	sfloat->zap = zap;
	sfloat->i_part = i_part;
	sfloat->num = num;
	sfloat->s = NULL;
	return (sfloat);
}
