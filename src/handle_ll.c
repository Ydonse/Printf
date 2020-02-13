/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:13:31 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:49:44 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_lld(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = va_arg(*ap, long long);
	list->type_str = ft_llitoa(list->type.ll);
	list->type_str = add_attributes(list, (long double)list->type.ll);
	list->skip += skip;
}

void	handle_llu(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = va_arg(*ap, long long);
	list->type_str = ft_lutoa(list->type.ll);
	list->uns = 1;
	list->type_str = add_attributes(list, (long double)list->type.ll);
	list->skip += skip;
}

void	handle_llo(t_plist *list, va_list *ap, int skip)
{
	list->type.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = OCTAL;
	list->type_str = convert_octal(list->type.llu);
	list->type_str = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
}

void	handle_llx(t_plist *list, va_list *ap, int skip)
{
	list->type.llu = va_arg(*ap, long long);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa(list->type.llu, list);
	list->type_str = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
}

void	handle_llx_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = HEXA_HIGH;
	list->type_str = convert_hexa(list->type.llu, list);
	list->type_str = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
}
