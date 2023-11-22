/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:19:11 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/22 14:23:53 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	char	digit;
	long	num;
	int		length;

	num = (long)n;
	length = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		length += 1;
	}
	if (n / 10)
	{
		length += 1;
		ft_putnbr_fd(num / 10, fd);
	}
	digit = '0' + (num % 10);
	write(1, &digit, 1);
	return (length);
}

int	my_formats(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
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
