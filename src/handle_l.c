/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:42:51 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:06:53 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ld(t_plist *list, va_list *ap, int skip)
{
	list->type.l = va_arg(*ap, long);
	list->type_str = ft_llitoa((long long)list->type.l);
	list->type_str = add_attributes(list, (long double)list->type.l);
	list->skip += skip;
}

void	handle_lo(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = OCTAL;
	list->type_str = convert_octal((unsigned long long)list->type.lu);
	list->type_str = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}

void	handle_lu(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->type_str = ft_lutoa(list->type.lu);
	list->uns = 1;
	list->type_str = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}

void	handle_lx(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa((unsigned long long)list->type.lu, list);
	list->type_str = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}

void	handle_lx_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_HIGH;
	list->type_str = convert_hexa((unsigned long long)list->type.lu, list);
	list->type_str = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}
