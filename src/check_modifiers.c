/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:20:31 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/05 16:50:56 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_l_type(t_plist *list, const char *str_ptr, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_l[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_ld, handle_ld, handle_lu, handle_lo, handle_lx,
			handle_lx_maj, handle_lf, handle_llu};

	if ((i = flags_cmp(str_ptr + 1, "diuoxXfU", 8)) != -1)
		function_l[i](list, ap, skip);
	else if (str_ptr[1] == 'l')
		check_ll_type(list, str_ptr + 1, ap, skip + 1);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if ((i = flags_cmp(str_ptr + 1, "diuoxXfU", 8)) != -1)
			function_l[i](list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else
		handle_null(list, str_ptr + 1, skip);
}

static void		check_h_type(t_plist *list, const char *str_ptr, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_h[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_hd, handle_hd, handle_hu, handle_ho,
		handle_hx, handle_hx_maj, handle_lu};

	if (str_ptr[1] == 'h')
		check_hh_type(list, str_ptr + 1, ap, skip + 1);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
			function_h[i](list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
		function_h[i](list, ap, skip);
	else
		handle_null(list, str_ptr + 1, skip);
}

static void		check_j_type(t_plist *list, const char *str_ptr, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_j[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_lld, handle_llu, handle_llx, handle_llx_maj,
			handle_lld, handle_llo, handle_llu};

	i = 0;
	if ((i = flags_cmp(str_ptr + 1, "duxXioU", 7)) != -1)
		function_j[i](list, ap, skip);
	else if (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
	{
		while (flags_cmp(str_ptr + 1, "hlLjz", 5) != -1)
		{
			str_ptr++;
			skip++;
		}
		if ((i = flags_cmp(str_ptr + 1, "diuoxXU", 7)) != -1)
			function_j[i](list, ap, skip);
		else
			handle_null(list, str_ptr + 1, skip);
	}
	else
		handle_null(list, str_ptr + 1, skip);
}

static void		check_x_type(t_plist *list, const char *str_ptr, va_list *ap)
{
	static void (*function_x[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_d, handle_s, handle_p, handle_u, handle_c, handle_x,
		handle_xmaj, handle_f, handle_d, handle_o, handle_lu, handle_percent};
	int			i;

	i = 0;
	if ((i = flags_cmp(str_ptr, "dspucxXfioU%", 12)) != -1)
		function_x[i](list, ap, 1);
	else
		handle_null(list, str_ptr, 1);
}

void			check_modifiers(t_plist *list, const char *str_ptr, va_list *ap)
{
	if (*str_ptr == 'l' || *str_ptr == 'z')
		check_l_type(list, str_ptr, ap, 2);
	else if (*str_ptr == 'h')
		check_h_type(list, str_ptr, ap, 2);
	else if (*str_ptr == 'j')
		check_j_type(list, str_ptr, ap, 2);
	else if (*str_ptr == 'L')
		check_l_maj_type(list, str_ptr, ap, 2);
	else
		check_x_type(list, str_ptr, ap);
}
