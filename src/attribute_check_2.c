/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:53:15 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/05 14:03:14 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_field(t_plist *list, const char *str_ptr)
{
	list->min_w = ft_atoi(str_ptr);
	while (*str_ptr >= '0' && *str_ptr <= '9')
	{
		list->skip++;
		str_ptr++;
	}
}

void	handle_zero(t_plist *list, const char *str_ptr)
{
	list->zero = 1;
	list->skip++;
	(void)str_ptr;
}

void	handle_space(t_plist *list, const char *str_ptr)
{
	list->space = 1;
	list->skip++;
	(void)str_ptr;
}

void	handle_precision(t_plist *list, const char *str_ptr)
{
	list->dot = 1;
	if (str_ptr[1] >= '0' && str_ptr[1] <= '9')
	{
		list->dot_size = ft_atoi(&str_ptr[1]);
		if (str_ptr[1] == '-' || str_ptr[1] == '+')
		{
			list->skip++;
			str_ptr++;
		}
		while (str_ptr[1] >= '0' && str_ptr[1] <= '9')
		{
			str_ptr++;
			list->skip++;
		}
		list->skip++;
	}
	else
	{
		list->dot_size = 0;
		list->skip++;
	}
}
