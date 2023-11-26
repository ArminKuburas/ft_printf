/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:24:24 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 13:25:14 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
