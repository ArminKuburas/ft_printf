/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:23:43 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 13:59:46 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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