/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:52:00 by kfortin           #+#    #+#             */
/*   Updated: 2022/05/31 16:50:23 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb2;
	int		print_count;

	nb2 = n;
	print_count = 0;
	if (nb2 < 0)
	{
		nb2 = -nb2;
		ft_putchar_fd('-', fd);
		print_count++;
	}
	if (nb2 < 10)
	{
		return (print_count += ft_putchar_fd(nb2 + 48, fd));
	}
	if (nb2 >= 10)
	{
		print_count += ft_putnbr_fd(nb2 / 10, fd);
		return (print_count + ft_putnbr_fd(nb2 % 10, fd));
	}
	return (print_count);
}
