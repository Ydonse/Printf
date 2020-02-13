/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:52:57 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:06:42 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hhd(t_plist *list, va_list *ap, int skip)
{
	list->type.c = (char)va_arg(*ap, int);
	list->type_str = ft_itoa((int)list->type.c);
	list->type_str = add_attributes(list, (long double)list->type.c);
	list->skip += skip;
}

void	handle_hhu(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->type_str = ft_itoa((int)list->type.uc);
	list->type_str = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}

void	handle_hho(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, int);
	list->mode = OCTAL;
	list->type_str = convert_octal((unsigned int)list->type.uc);
	list->type_str = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}

void	handle_hhx(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa((unsigned int)list->type.uc, list);
	list->type_str = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}

void	handle_hhx_maj(t_plist *list, va_list *ap, int skip)
{
	list->type.uc = (unsigned char)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->type_str = convert_hexa((unsigned int)list->type.uc, list);
	list->type_str = add_attributes(list, (long double)list->type.uc);
	list->skip += skip;
}
