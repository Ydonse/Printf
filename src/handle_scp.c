/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:16:46 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/05 14:04:10 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(t_plist *list, va_list *ap, int skip)
{
	list->type.str = va_arg(*ap, char*);
	if (list->type.str)
		list->type_str = ft_strdup(list->type.str);
	else
	{
		list->type_str = ft_strdup("(null)");
		list->type.c = '.';
	}
	list->type_entree = character;
	list->string = 1;
	list->type_str = add_attributes(list, 0);
	list->skip += skip;
}

void	handle_p(t_plist *list, va_list *ap, int skip)
{
	list->sharp = 1;
	list->pointer = 1;
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->type_str = convert_hexa(list->type.lu, list);
	list->type_str = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
}

void	handle_c(t_plist *list, va_list *ap, int skip)
{
	list->type.c = (char)va_arg(*ap, int);
	if (!list->type.c)
	{
		list->type_str = ft_strnew(1);
	}
	else
		list->type_str = ft_strdup(&(list->type.c));
	list->type_entree = character;
	list->type_str = add_attributes(list, 0);
	list->skip += skip;
}

void	handle_percent(t_plist *list, va_list *ap, int skip)
{
	list->type.c = '%';
	list->type_str = ft_strdup("%");
	list->type_entree = character;
	list->percent = 1;
	list->type_str = add_attributes(list, 0);
	list->skip += skip;
	(void)ap;
}
