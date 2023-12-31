/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:32:18 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/01 13:31:37 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_puthex(unsigned int nbr, int uppercase, int *length);
int	ft_ptrhex(unsigned long ptr, int *length);
int	ft_putstr(char *string);
int	ft_put_u_nbr(unsigned int n, int *length);
int	ft_putchar(char c);
int	ft_putnbr(int n, int *length);
int	ft_printf(const char *str, ...);
#endif