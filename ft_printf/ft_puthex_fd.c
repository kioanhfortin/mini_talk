/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:37:43 by kfortin           #+#    #+#             */
/*   Updated: 2022/05/31 16:50:32 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(size_t n, int i)
{
	char	*base1;
	char	*base2;
	int		print_count;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	print_count = 0;
	if (n >= 16)
		print_count += ft_puthex_fd(n / 16, i);
	if (i >= 0)
		return (print_count + ft_putchar_fd(base1[n % 16], 1));
	else
		return (print_count + ft_putchar_fd(base2[n % 16], 1));
	return (print_count);
}
