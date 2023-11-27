/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:41:02 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/27 16:29:50 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrhex(unsigned long ptr, int *length)
{
	const char	*hex_digits;
	int			check;

	hex_digits = "0123456789abcdef";
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		(*length) += 5;
	}
	if (ptr >= 16)
	{
		ft_ptrhex(ptr / 16, length);
	}
	(*length)++;
	check = ft_putchar(hex_digits[ptr % 16]);
	if (check == -1)
		return ((*length) - (*length) - 1);
	return (*length);
}
