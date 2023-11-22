/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:16:47 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/21 16:18:35 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	value;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			value = va_arg(args, int);
			write(1, "This is where you print the integer", 35);
			format += 2;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("ahahaha %d", 1);
	return (0);
}