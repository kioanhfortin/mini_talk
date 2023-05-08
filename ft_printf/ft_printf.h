/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:42:43 by kfortin           #+#    #+#             */
/*   Updated: 2022/06/15 13:52:34 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar_fd(char c, int fd);
int	ft_printf(const char *str, ...);
int	ft_putstr_fd(char *s, int fd);
int	ft_puthex_fd(size_t n, int i);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunsignednbr_fd(unsigned int n, int fd);

#endif