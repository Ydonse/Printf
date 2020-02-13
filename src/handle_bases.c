/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:14:40 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/04 11:15:02 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_o(t_plist *list, va_list *ap, int skip)
{
	list->type.u = va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->type_str = convert_octal(list->type.u);
	list->type_str = add_attributes(list, (long double)list->type.u);
	list->skip += skip;
}

void	handle_x(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa(list->type.ll, list);
	list->type_str = add_attributes(list, list->type.ll);
	list->skip += skip;
}

void	handle_xmaj(t_plist *list, va_list *ap, int skip)
{
	list->type.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_HIGH;
	list->type_str = convert_hexa(list->type.ll, list);
	list->type_str = add_attributes(list, list->type.ll);
	list->skip += skip;
}
