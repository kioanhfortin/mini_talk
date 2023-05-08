/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:46:31 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/09 15:02:08 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_variable(const char c, va_list arg)
{
	int	len_print;

	len_print = 0;
	if (c == 'c')
		len_print = ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		len_print = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		len_print = ft_puthex_fd(va_arg(arg, unsigned long), 0);
		len_print += 2;
	}
	else if (c == 'd' || c == 'i')
		len_print = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		len_print = ft_putunsignednbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		len_print = ft_puthex_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		len_print = ft_puthex_fd(va_arg(arg, unsigned int), -1);
	else if (c == '%')
		len_print = ft_putchar_fd('%', 1);
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		res;
	va_list	arg;

	i = 0;
	j = 0;
	res = 0;
	if (!*str)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			res += ft_print_variable(str[++i], arg);
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		++i;
	}
	va_end(arg);
	return (res + j);
}
