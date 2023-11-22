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

int	my_formats(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
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
	ft_printf("%d\n", ft_printf(""));
	printf("%d\n", ft_printf(""));
	return (0);
}
