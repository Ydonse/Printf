/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:59:40 by ydonse            #+#    #+#             */
/*   Updated: 2019/02/28 16:33:49 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base_size(unsigned long long nb, unsigned long long base)
{
	int i;

	i = 1;
	while (nb > base - 1)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*convert_hexa(unsigned long long nb, t_plist *list)
{
	static const char	hexa_str[17] = "0123456789abcdef";
	int					i;
	char				*str;

	i = get_base_size(nb, 16);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i -= 1;
	while (nb > 15)
	{
		str[i] = hexa_str[nb % 16];
		if (list->mode == HEXA_HIGH && nb % 16 > 9)
			str[i] -= 32;
		i--;
		nb /= 16;
	}
	str[i] = hexa_str[nb];
	if (list->mode == HEXA_HIGH && nb % 16 > 9)
		str[i] -= 32;
	return (str);
}

char	*convert_octal(unsigned long long nb)
{
	unsigned long long		nb_cpy;
	int						i;
	char					*str;

	nb_cpy = nb;
	i = get_base_size(nb, 8);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i -= 1;
	while (nb > 7)
	{
		str[i--] = nb % 8 + '0';
		nb /= 8;
	}
	str[i] = nb + '0';
	return (str);
}
