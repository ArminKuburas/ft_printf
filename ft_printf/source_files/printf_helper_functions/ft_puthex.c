/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:45:24 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 14:37:26 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned int nbr, int uppercase, int *length)
{
	const char	*hex_digits;

	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (uppercase == 0)
		hex_digits = "0123456789abcdef";
	else if (uppercase == 1)
		hex_digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16, uppercase, length);
	}
	(*length)++;
	ft_putchar(hex_digits[nbr % 16]);
	return (*length);
}
