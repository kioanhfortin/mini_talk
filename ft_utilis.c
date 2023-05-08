/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:00:36 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/10 16:49:16 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = count * size;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	ft_memset(str, 0, i);
	return (str);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	char	*strjoin;
	int		i;
	int		len1;
	int		len2;

	i = -1;
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = 1;
	strjoin = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	while (++i < len1)
		strjoin[i] = s1[i];
	if (s1)
		free(s1);
	strjoin[i] = s2;
	strjoin[i + 1] = '\0';
	return (strjoin);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dup == 0)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
