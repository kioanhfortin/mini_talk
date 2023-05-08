/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:03:54 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/10 16:49:03 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

typedef struct  s_ps
{
    int i;
    int buff_size;
    int max;
    unsigned char byte;
    char *msg;
} t_ps;

t_ps    ps;

// void    ft_handler()
// {
//     write(STDOUT_FILENO, "I don't die\n", 13);
// }

// void    ft_handler1(int signum, siginfo_t *s_info, void *content)
// {
//     // int j;
//     int pid;
//     static  t_ps    ps;

//     ps.i = 8;
//     pid = getpid();
//     (void)content;
//     (void)s_info;
//     if (ps.i == 0)
//     {
//         printf("end");
//         ps.i = 8;
//     }
//     write(1, "hiri", 4);
//     if (ps.i >= 0)
//     {
//         if (signum == SIGUSR1)
//         {
//             write(1, "horo", 4);
//             if (!ps.byte[0])
//             {
//                 ps.byte = ft_calloc(1, sizeof(char));
//                 if (!ps.byte)
//                     return ;
//                 ps.byte[ps.i] = '1';
//                 ps.i--;
//             }
//             else
//             {
//                 printf("1 %s\n", ps.byte);
//                 ft_strjoin(ps.byte, "1");
//                 ps.i--;
//             }
//         }
//         if (signum == SIGUSR2)
//         {
            
//             // if (ps.i == 0)
//             // {
//             //     printf("end");
//             //     ps.i = 8;
//             // }
//             write(1, "huru", 4);
//             if (!ps.byte[0])
//             {
//                 ps.byte = ft_calloc(1, sizeof(char));
//                 if (!ps.byte)
//                     return ;
//                 ps.byte[ps.i] = '0';
//                 ps.i--;
//             }
//             else
//             {
//                 ft_strjoin(ps.byte, "0");
//                 ps.i--;
//             }
//             printf("2 %s\n", ps.byte);
//         }
//     }
//     else
//         ps.byte[ps.i] <<= 1;
    // printf("string : %s\n", byte);
    // c_msg = ft_atoi(byte);
    // free(byte);
    // write(STDOUT_FILENO, "USER1\n", 13);
// }

// void    ft_handler2(int signum)
// {
//     // int j;
//     int pid;
//     static  t_ps    ps;

//     ps.i = 8;
//     pid = getpid();
//     if (signum == SIGUSR2)
//     {
//         if (ps.i == 0)
//         {
//             printf("end");
//             ps.i = 8;
//         }
//         if (!ps.byte[0])
//         {
//             ps.byte = ft_calloc(1, sizeof(char));
//             if (!ps.byte)
//                 return ;
//             ps.byte[ps.i] = '0';
//             ps.i--;
//         }
//         else
//         {
//             ft_strjoin(ps.byte, "0");
//             ps.i--;
//         }
//     }
// }

// void    ft_stock_byte(t_ps  ps);
// {
//     if (!ps.msg[0])
//     {
//         ft_strdup(ps.msg);
//     }
//     else
//     {
//         ft_strjoin(ps.msg, ps.byte);
//     }
// }

void    ft_handler1(int signum, siginfo_t *s_info, void *content)
{
    int len;

    len = 0;
    (void)content;
    (void)s_info;
    ps.byte += (signum == SIGUSR2);
    if (++ps.i == 8)
    {
        if (ps.byte != '\0')
        {
            if (!ps.msg)
            {
                ps.msg = ft_calloc(2, sizeof(char));
                ps.msg[0] = ps.byte;
                ps.msg[1] = '\0';
            }
            else
            {
                ps.msg = ft_strjoin_char(ps.msg, ps.byte);
            }
        }
        else
        {
            ft_printf("%s\n", ps.msg);
            if (ps.msg)
            {
                free(ps.msg);
                ps.msg = NULL;
            }
        }
        ps.i = 0;
        ps.byte = 0;
    }
    else
        ps.byte <<= 1;
}

// void    ft_seghandler()
// {
//     write(STDOUT_FILENO, "Seg fault\n", 10);
//     exit(0);
// }

// void    ft_init_struct(t_ps *tab)
// {
//     tab->j = 0;
//     tab->byte = '\0';
//     tab->msg[0] = '\0';
// }

int main()
{
    struct  sigaction sa;

    // ft_init_struct(&tab);
    sa.sa_sigaction = &ft_handler1;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    // signal(SIGINT, ft_handler);
    // signal(SIGUSR1, ft_handler1);
    // signal(SIGUSR2, ft_handler2);
    // signal(SIGTERM, ft_seghandler);
    ft_printf("PID serveur : %d\n", getpid());
    while(1)
    {
        usleep(1);
    }
}

