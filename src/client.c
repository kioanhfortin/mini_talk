/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:50:06 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/16 16:34:16 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_msg_binary(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & 128)
		{
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		usleep(100);
		c <<= 1;
		i--;
	}
}

void	ft_msg_receive(int signum, siginfo_t *s_info, void *content)
{
	(void)content;
	(void)s_info;
	if (signum == SIGUSR1)
		ft_printf("Message receive\n");
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;
	int					i;
	int					len;

	i = 0;
	if (argc != 3)
		return (0);
	sa.sa_sigaction = ft_msg_receive;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	while (i <= len)
	{
		ft_msg_binary(argv[2][i], pid);
		i++;
	}
}
