/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:14:25 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/02 11:10:52 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_plus(t_plist *list, long double nb, int i, char *str)
{
	if (list->plus == 1 && nb >= 0 && !list->mode &&
		list->type_entree == number && !list->uns)
		str[i++] = '+';
	i = check_space(list, nb, i, str);
	return (i);
}

int	check_space(t_plist *list, long double nb, int i, char *str)
{
	if (list->space == 1 && nb >= 0 && !list->mode
		&& !list->plus && list->type_entree == number && !list->uns)
		str[i++] = ' ';
	return (i);
}
