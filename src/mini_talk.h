/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:54 by kfortin           #+#    #+#             */
/*   Updated: 2022/11/16 16:49:38 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps
{
	int				i;
	int				buff_size;
	int				max;
	int				pid;
	unsigned char	byte;
	char			*msg;
}					t_ps;

void				signal_handler1(int sig);
void				ft_msg_binary(char c, pid_t pid);
void				ft_handler(void);
void				ft_handler1(int signum, siginfo_t *s_info, void *content);
void				ft_seghandler(void);
int					ft_strlen(char *str);
int					ft_isspace(char *str, int i);
int					check_base(char *base);
int					is_base(char c, char *base);
int					ft_atoi_base(char *str, char *base);
int					len_num(int nbr, char *base_to);
void				ft_putnbr_base(int len, int nbr, char *str, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_atoi(char *str);
char				*ft_strdup(char *src);
char				*ft_strjoin_char(char *s1, char s2);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
int					ft_printf(const char *str, ...);

#endif