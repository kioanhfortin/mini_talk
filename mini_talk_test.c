/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:17 by kfortin           #+#    #+#             */
/*   Updated: 2022/10/26 16:21:54 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int x = 100;

void    signal_handler1(int sig)
{
    (void)sig;
    x += 5;
    printf("x=%d\n", x);
}

void    signal_handler2(int sig)
{
    (void)sig;
    x += 10;
    printf("x=%d\n", x);
}

void    signal_handler3(int sig)
{
    (void)sig;
    x += 20;
    printf("x=%d\n", x);
}

int main()
{
    pid_t pid;
    signal(SIGINT, signal_handler1);
    signal(SIGUSR2, signal_handler3);

    pid = fork();
    if (pid == 0)
    {
        pid_t   parent = getppid();
        kill(parent, SIGINT);
        sleep(1);
        kill(parent, SIGUSR1);
        sleep(1);
        kill(parent, SIGUSR2);
        sleep(1);
        return (0);
    }
    else
    {
        int stat;

        stat = 0;
        usleep(stat);
    }
    return (0);
}