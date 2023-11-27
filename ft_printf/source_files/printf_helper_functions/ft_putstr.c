/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:25:09 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/27 15:28:22 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *string)
{
	int	i;
	int	result;

	result = 0;
	if (string == NULL)
	{
		result = write(1, "(null)", 6);
		if (result == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (string[i])
	{
		result = ft_putchar(string[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
