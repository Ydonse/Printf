/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_du.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:16:33 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/05 11:15:53 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(t_plist *list, va_list *ap, int skip)
{
	list->type.i = va_arg(*ap, int);
	list->type_str = ft_itoa(list->type.i);
	list->type_str = add_attributes(list, (long double)list->type.i);
	list->skip += skip;
}

void	handle_u(t_plist *list, va_list *ap, int skip)
{
	list->type.u = va_arg(*ap, unsigned int);
	list->type_str = ft_llitoa((long long)list->type.u);
	list->uns = 1;
	list->type_str = add_attributes(list, (long double)list->type.u);
	list->skip += skip;
}
