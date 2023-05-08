/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:50:06 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/10 14:11:03 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

char *msg = NULL;

// void    signal_handler1(int sig)
// {
    // (void)sig;
    // x += 5;
    // printf("x=%d\n", x);
// }


// void    ft_send_msg(char c, pid_t pid)
// {
//     if (c == '1')
//         kill(pid, SIGUSR1);
//     if (c == '0')
//         kill(pid, SIGUSR2);
// }

// void    ft_msg_binary(char c, pid_t pid)
// {
//     // int j;
//     int i;
//     char char_bin;

//     i = 7;
//     // j = 0;
//     while (i >= 0)
//     {
//         char_bin = (c & (1 << i)) ? '1' : '0';
//         if (char_bin == '1')
//         {
//             write(1, &char_bin, 1);
//             kill(pid, SIGUSR1);
//         }
//         if (char_bin == '0')
//             kill(pid, SIGUSR2);
//         // j++;
//         i--;
//     }
// }

void    ft_msg_binary(char c, pid_t pid)
{
    int i;

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

int main(int argc, char **argv)
{
    pid_t   pid;
    // struct  sigaction sa;
    int i;
    int len;
    
    (void)argc;
    i = 0;
    // sa.sa_sigaction = ft_msg_binary;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGUSR1, &sa, NULL);
    // sigaction(SIGUSR2, &sa, NULL);
    pid = ft_atoi(argv[1]);
    len = ft_strlen(argv[2]);
    while (i <= len)
    {
        ft_msg_binary(argv[2][i], pid);
        i++;
    }
    // printf("%s\n", msg);
    // ft_send_msg(msg, pid);
    // kill(pid, SIGUSR1);
        // kill(pid, mes);
}
