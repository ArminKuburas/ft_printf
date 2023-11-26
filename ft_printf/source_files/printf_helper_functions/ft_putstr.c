/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:25:09 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/26 14:37:07 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
