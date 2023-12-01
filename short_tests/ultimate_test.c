/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:57:00 by akuburas          #+#    #+#             */
/*   Updated: 2023/11/30 15:44:58 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	void *ptr = "";
	char *str = "";
	ft_printf("ft_printf results for negative numbers conversions d, %%, i and u = %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1);
	printf("printf results for negative numbers conversions d, %%, i and u =: %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1);
	ft_printf("amounted printed checked by ft_printf for ft_printf = %d\n", ft_printf("ft_printf results: %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1));
	printf("amounted printed checked by printf for printf = %d\n", printf("ft_printf results: %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1));
	ft_printf("amounted printed checked by ft_printf for printf = %d\n", printf("ft_printf results: %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1));
	printf("amounted printed checked by printf for ft_printf = %d\n", ft_printf("ft_printf results: %d\t%%%d\t%i\t%u\n", -1, -1, -1, -1));
	ft_printf("ft_printf results: %d\t%%%d\t%i\t%u\n", 1, 1, 1, 1);
	printf("printf results: %d\t%%%d\t%i\t%u\n", 1, 1, 1, 1);
	ft_printf("Now lets check for extreme cases: %d\t%d\t%d\t%u", 0, INT_MAX, INT_MIN, UINT_MAX);
	ft_printf("\nloading loading. You have failed! Nah jk lets continue\n");
	ft_printf("Wow okay now lets try the hex numbers 0.0 wowzers zomg?\n");
	ft_printf("This is ft_printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL);
	printf("This is printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL);
	ft_printf("ft_printf testing output value of ft_printf = %d\n", ft_printf("This is ft_printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL));
	ft_printf("ft_printf testing output value of printf = %d\n", printf("This is printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL));
	printf("printf testing output value of ft_printf = %d\n", ft_printf("This is ft_printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL));
	printf("printf testing output value of printf = %d\n", printf("This is printf testing for X, x and p = %x\t%X\t%p\t%p\n", 16, 16, ptr, (void *) NULL));
	ft_printf("ft_printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48);
	printf("printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48);
	ft_printf("ft_printf testing output of ft_printf = %d\n", ft_printf("ft_printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48));
	ft_printf("ft_printf testing output of printf = %d\n", printf("printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48));
	printf("printf testing output of ft_printf = %d\n", ft_printf("ft_printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48));
	printf("printf testing output of printf = %d\n", printf("printf string and character test: %s\t%s\t%c\t%c\n", str, "Yippe mom let me have some coca cola :)", '%', 48));
	return (0);
}
