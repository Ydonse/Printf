/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:53:15 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/05 14:02:53 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_sharp(t_plist *list, const char *str_ptr)
{
	list->sharp = 1;
	list->skip++;
	(void)str_ptr;
}

void	handle_plus(t_plist *list, const char *str_ptr)
{
	list->plus = 1;
	list->skip++;
	(void)str_ptr;
}

void	handle_minus(t_plist *list, const char *str_ptr)
{
	list->minus = 1;
	list->skip++;
	(void)str_ptr;
}

int		flags_a_cmp(char c, const char *flags)
{
	int i;

	i = 0;
	while (*flags)
	{
		if (c == *flags)
			return (i);
		flags++;
		i++;
	}
	return (-1);
}

void	check_attribute_1(t_plist *list, const char *str_ptr, va_list *ap)
{
	static const char	attributes[] = "0123456789-+.# ";
	static void			(*functions[])(t_plist*, const char *) = { &handle_zero,
		&handle_field, &handle_field, &handle_field,
		&handle_field, &handle_field, &handle_field, &handle_field,
		&handle_field, &handle_field, &handle_minus, &handle_plus,
		&handle_precision, &handle_sharp, &handle_space};
	int					i;

	i = 0;
	while ((i = flags_a_cmp(*str_ptr, attributes)) > -1)
	{
		functions[i](list, str_ptr);
		str_ptr = i == 12 ? str_ptr + 1 : str_ptr;
		if ((i > 0 && i < 10) || i == 12)
		{
			while (*str_ptr >= '0' && *str_ptr <= '9')
				str_ptr++;
		}
		else
			str_ptr++;
	}
	check_modifiers(list, (const char *)str_ptr, ap);
}
