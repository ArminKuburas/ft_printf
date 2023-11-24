/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:26 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:58 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

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
		ft_putnbr(num / 10);
	}
	digit = '0' + (num % 10);
	write(1, &digit, 1);
	return (length);
}

int	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		i += ft_putchar(string[i]);
	}
	return (i);
}

static int	ft_puthex(uintptr_t n)
{
	const char	*hex_digits;
	int			length;

	hex_digits = "0123456789abcdef";
	length = 0;
	if (n >= 16)
		ft_puthex(n / 16);
	length += ft_putchar(hex_digits[n % 16]);
	return (length);
}

int	my_formats(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putstr("0x") + ft_puthex((uintptr_t)ptr));
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

int	main(void)
{
	void *empty;
	ft_printf("mine: %p\n", empty);
	printf("original: %p\n", empty);
	return (0);
}
