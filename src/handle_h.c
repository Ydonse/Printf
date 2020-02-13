/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:52:57 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 12:28:35 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hd(t_plist *list, va_list *ap, int skip)
{
	list->type.s = (short)va_arg(*ap, int);
	list->type_str = ft_itoa(list->type.s);
	list->type_str = add_attributes(list, (long double)list->type.s);
	list->skip += skip;
}

void	handle_hu(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->type_str = ft_llitoa((long long)list->type.us);
	list->uns = 1;
	list->type_str = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}

void	handle_ho(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->type_str = convert_octal((unsigned int)list->type.us);
	list->type_str = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}

void	handle_hx(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa((unsigned int)list->type.us, list);
	list->type_str = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}

void	handle_hx_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->type_str = convert_hexa((unsigned int)list->type.us, list);
	list->type_str = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
}
