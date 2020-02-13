/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_modifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:20:31 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/06 09:46:49 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_null(t_plist *list, const char *str_ptr, int ptr)
{
	list->type.c = *str_ptr;
	if (!list->type.c)
	{
		list->type.c = '.';
		list->type_str = ft_strnew(1);
	}
	else
	{
		list->type_str = ft_strdup(&(list->type.c));
	}
	list->type_entree = character;
	list->skip += ptr;
	if (list->type_str[0] == '\0')
		list->skip--;
	list->type_str = add_attributes(list, 0);
}

int		flags_cmp(const char *str, const char *flags, int size)
{
	int	j;

	j = 0;
	while (j < size && flags[j])
	{
		if (str[0] == flags[j])
			return (j);
		else
			j++;
	}
	return (-1);
}

void	check_ll_type(t_plist *list, const char *str_ptr, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_ll[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_lld, handle_lld, handle_llu, handle_llo, handle_llx,
		handle_llx_maj, handle_llu};

	i = 0;
	if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
		function_ll[i](list, ap, skip);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
			function_ll[i](list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else
		handle_null(list, str_ptr + 1, skip);
}

void	check_hh_type(t_plist *list, const char *str_ptr, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_hh[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_hhd, handle_hhd, handle_hhu, handle_hho,
		handle_hhx, handle_hhx_maj};

	i = 0;
	if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
		function_hh[i](list, ap, skip);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
			function_hh[i](list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else
		handle_null(list, str_ptr + 1, skip);
}

void	check_l_maj_type(t_plist *list, const char *str_ptr,
	va_list *ap, int skip)
{
	if (str_ptr[1] == 'f')
		handle_maj_lf(list, ap, skip);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if (str_ptr[1] == 'f')
			handle_maj_lf(list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else
		handle_null(list, str_ptr + 1, 2);
}
