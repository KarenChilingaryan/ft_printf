/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simbols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:39:11 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 10:58:47 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		stugum(char *str, va_list args, int i, t_flags *flags)
{
	char *src;
	char *line[2];

	src = NULL;
	flags->type = str[i];
	src = createstr(flags, str);
	line[0] = src;
	line[1] = str;
	if (str[i] == 'c')
		ft_char(va_arg(args, int), src, flags);
	if (str[i] == 's')
		ft_str(va_arg(args, char *), src, flags, str);
	if (str[i] == 'd' || str[i] == 'i')
		ft_int(va_arg(args, int), src, flags, str);
	if (str[i] == 'u')
		ft_unsigint(va_arg(args, int), src, flags, str);
	if (str[i] == 'p')
		ft_pointer((unsigned long long)va_arg(args, void*), src, flags, str);
	if (str[i] == 'x' || str[i] == 'X')
		ft_putnbrx(va_arg(args, unsigned long long), str[i], line, flags);
	if (str[i] == '%')
		ft_percent(src, flags);
	return (i + 1);
}

int		ft_charletter(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		charelem(int c)
{
	return ((c == '-') || (c == '0') ||
			(c == '.') || (c == '*') || (c > '0' && c <= '9'));
}

char	*negativestr(char *src, t_flags *flags)
{
	char	*str;
	int		arr[4];

	arr[0] = 0;
	while (src[arr[0]] && src[arr[0]] != ' ')
		arr[0]++;
	if (arr[0] == (int)ft_strlen(src))
		arr[3] = arr[0] + 1;
	else
		arr[3] = flags->integer1;
	str = malloc(sizeof(char) * arr[3] + 1);
	arr[1] = 0;
	if (arr[0] == (int)ft_strlen(src))
		allfuncsrc(str, arr, src, flags);
	else
		allfuncsrc1(src, str, arr);
	str[arr[1]] = '\0';
	return (str);
}
