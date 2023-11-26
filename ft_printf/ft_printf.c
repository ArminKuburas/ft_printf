/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:19:11 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 13:49:50 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), &length));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_ptrhex((unsigned long)va_arg(args, void *), &length));
	}
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0, &length));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, &length));
	else if (format == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int), &length));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += my_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
