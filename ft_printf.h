/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:49:20 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/23 11:52:45 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <inttypes.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				dot;
	int				minus;
	int				zero;
	int				width1;
	int				width2;
	int				integer1;
	int				integer2;
	int				negative;
	int				len;
	char			type;
}					t_flags;
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
int					ft_char(char c, char *src, t_flags *flags);
int					ft_str(char *str, char *src, t_flags *flags, char *strdes);
int					ft_unsigint(int unsigitoa, char *src,
									t_flags *flags, char *dest);
int					ft_pointer(unsigned long long address, char *src,
									t_flags *flags, char *dest);
int					ft_putnbrx(unsigned long long intx, char c,
									char **line, t_flags *flags);
int					ft_int(int intitoa, char *src, t_flags *flags, char *dest);
int					stugum(char *str, va_list args, int i, t_flags *src);
int					ft_charletter(char c);
int					ft_charsimbol(int i, t_flags *flags,
									va_list args, char *str);
int					charelem(int c);
int					ft_atoi(const char *str);
int					inputelem(t_flags *flags, char *str, va_list args, int i);
int					fooooo1(char *str, char *src, t_flags *flags, char *line);
int					ft_percent(char *src, t_flags *flags);
char				*space(int c);
char				*esiminch(int n, char *str);
char				*negativestr(char *src, t_flags *flags);
char				*allfuncsrc(char *str, int *arr, char *src, t_flags *flags);
char				*allfuncsrc1(char *src, char *str, int *arr);
char				*flagpointnum1(char *str, int *arr, char *dest);
char				*flagpointnum(char *str, int *arr, char *dest);
char				*ft_strdup(const char *s1);
char				*ft_itoa(int n);
char				*ft_putnbr_base_pointer(unsigned int nbr, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*createstr(t_flags *flags, char *str);
char				*ft_putnbr_base_pointerflag(unsigned long long nbr, int c);
char				*foonaem(char *strdes, t_flags *flags, char *srt);
char				*foonaem1(char *strdes, t_flags *flags, char *dest);
char				*gnlneg(char *str);
char				*zeroflag(int c);
char				stugdest(t_flags *flags, char *dest, char *str, int *arr);
int					ft_printf(const char *input, ...);

#endif
