/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:03:54 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/16 18:11:57 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_ps	g_ps;

void	ft_print(void)
{
	ft_printf("%s\n", g_ps.msg);
	kill(g_ps.pid, SIGUSR1);
	if (g_ps.msg)
	{
		free(g_ps.msg);
		g_ps.msg = NULL;
	}
}

void	ft_handler1(int signum, siginfo_t *s_info, void *content)
{
	(void)content;
	g_ps.byte += (signum == SIGUSR2);
	if (s_info->si_pid)
		g_ps.pid = s_info->si_pid;
	if (++g_ps.i == 8)
	{
		if (g_ps.byte != '\0')
		{
			if (!g_ps.msg)
			{
				g_ps.msg = ft_calloc(2, sizeof(char));
				g_ps.msg[0] = g_ps.byte;
				g_ps.msg[1] = '\0';
			}
			else
				g_ps.msg = ft_strjoin_char(g_ps.msg, g_ps.byte);
		}
		else
			ft_print();
		g_ps.i = 0;
		g_ps.byte = 0;
	}
	else
		g_ps.byte <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handler1;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_ps.pid = getpid();
	ft_printf("PID serveur : %d\n", getpid());
	while (1)
	{
		usleep(1);
	}
}
