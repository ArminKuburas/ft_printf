/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:26 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 13:23:54 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef unsigned long	t_ul;

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n, int *length)
{
	char	digit;
	long	num;

	num = (long)n;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		(*length) += 1;
	}
	if (n / 10)
	{
		ft_putnbr(num / 10, length);
	}
	digit = '0' + (num % 10);
	(*length) += ft_putchar(digit);
	return (*length);
}

int	ft_put_u_nbr(unsigned int n, int *length)
{
	char	digit;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n / 10)
	{
		ft_put_u_nbr(n / 10, length);
	}
	digit = '0' + (n % 10);
	(*length) += ft_putchar(digit);
	return (*length);
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

static int	ft_ptrhex(t_ul ptr, int *length)
{
	const char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
	{
		ft_ptrhex(ptr / 16, length);
	}
	(*length)++;
	ft_putchar(hex_digits[ptr % 16]);
	return (*length);
}

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

int	my_formats(va_list args, const char format)
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
		return (2 + ft_ptrhex((t_ul)va_arg(args, void *), &length));
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

int	main(void)
{
	void *empty;
	unsigned int	digit = 1000;

	ft_printf("%u%%\n", digit);
	printf("%u%%\n", digit);
	ft_printf("%d\n", ft_printf("%u%%\n", digit));
	printf("%d\n", printf("%u%%\n", digit));
	return (0);
}
