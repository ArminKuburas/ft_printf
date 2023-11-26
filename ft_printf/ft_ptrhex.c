/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:41:02 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 13:46:17 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_ptrhex(unsigned long ptr, int *length)
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
