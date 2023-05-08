/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:05 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/31 16:06:17 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int		ft_isspace(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		return (1);
	return (0);
}

// int		check_base(char *base)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	if (ft_strlen(base) <= 1)
// 		return (0);
// 	while (base[i])
// 	{
// 		j = i + 1;
// 		while (base[j])
// 		{
// 			if (base[i] == base[j])
// 				return (0);
// 			j++;
// 		}
// 		if (base[i] == '+' || base[i] == '-' || ft_isspace(base, i) == 1 ||
// 		!(base[i] >= 32 && base[i] <= 126))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int		is_base(char c, char *base)
// {
// 	int i;

// 	i = 0;
// 	while (base[i])
// 	{
// 		if (c == base[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int		ft_atoi_base(char *str, char *base)
// {
// 	int i;
// 	int res;
// 	int sign;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	if (check_base(base) == 0)
// 		return (0);
// 	while (ft_isspace(str, i) == 1)
// 		i++;
// 	while (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = sign * -1;
// 		i++;
// 	}
// 	while (is_base(str[i], base) >= 0)
// 	{
// 		res = res * ft_strlen(base) + is_base(str[i], base);
// 		i++;
// 	}
// 	return (res * sign);
// }

// int		len_num(int nbr, char *base_to)
// {
// 	int	len;

// 	len = 0;
// 	if (nbr == 0)
// 		return (1);
// 	while (nbr)
// 	{
// 		nbr = nbr / ft_strlen(base_to);
// 		len++;
// 	}
// 	return (len);
// }

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// void	ft_putnbr_base(int len, int nbr, char *str, char *base)
// {
// 	if (nbr < 0)
// 	{
// 		nbr = -nbr;
// 		str[0] = '-';
// 	}
// 	if (nbr >= ft_strlen(base))
// 		ft_putnbr_base(len - 1, nbr / ft_strlen(base), str, base);
// 	str[len] = base[nbr % ft_strlen(base)];
// }

// char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
// {
// 	int		nb;
// 	int		len;
// 	char	*str;

// 	nb = 0;
// 	str = NULL;
// 	if (check_base(base_from) == 0 || check_base(base_to) == 0)
// 		return (NULL);
// 	nb = ft_atoi_base(nbr, base_from);
// 	len = len_num(nb, base_to);
// 	if (nb < 0)
// 		len++;
// 	if (!(str = malloc(sizeof(char) * len + 1)))
// 		return (NULL);
// 	ft_putnbr_base(len - 1, nb, str, base_to);
// 	str[len] = '\0';
// 	return (str);
// }

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str, i) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
