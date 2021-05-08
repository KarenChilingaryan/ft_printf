/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:06:18 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 11:07:17 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zeroflag(int c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * c + 1);
	while (i < c)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

char	*valod(int m, t_flags *flags, int j)
{
	char	*str;
	int		i;

	i = 0;
	if (flags->integer1 && flags->integer2)
		m = flags->integer1;
	else if (j == 0)
		m = 0;
	else
		m = flags->integer1;
	str = malloc(sizeof(char) * m);
	while (i < m)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*strnum(char *srt, char *strdes, t_flags *flags, char *str)
{
	if ((strdes[flags->dot - 1] == '%' && strdes[flags->dot + 1] == 's') ||
			(strdes[flags->dot - 1] == '%' && ((strdes[flags->dot + 1] == '0'
				&& strdes[flags->zero + 1] == 's') || (strdes[flags->dot + 1]
					== '*' && strdes[flags->width1 + 1] == 's'
						&& flags->integer1 == 0))))
		srt = "\0";
	else if (strdes[flags->dot + 1] == 's' && strdes[flags->dot - 1] >= '0' &&
				strdes[flags->dot - 1] <= '9' && (strdes[flags->width1 - 1]
					== '%' || (strdes[flags->width1 - 1] == '-' &&
						strdes[flags->width1 - 2] == '%')))
		srt = space(flags->integer1);
	else if (!flags->width1 && !flags->width2 && flags->dot
				&& flags->zero && flags->minus)
		srt = "\0";
	else if (flags->zero - flags->dot == 1 &&
				strdes[flags->dot - 1] == '-' && flags->integer1)
		flags->integer1 = ft_strlen(str);
	else if (!flags->minus && flags->width1 && flags->zero && flags->integer1 &&
			!flags->integer2 && !flags->width2 && !flags->dot)
		srt = str;
	return (srt);
}

int		strwhile(int *arr, char *src)
{
	while (src[arr[0]])
	{
		if (src[arr[0]] == '0')
			arr[1]++;
		else
			arr[2] = 1;
		src[arr[0]++] = ' ';
	}
	return (arr[1]);
}

int		ft_str(char *str, char *src, t_flags *flags, char *strdes)
{
	char	*srt;
	char	*dest;
	int		j;
	int		arr[3];
	int		num;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if (!str)
		str = "(null)\0";
	num = ft_strlen(str);
	if (flags->integer1 >= 0)
		num = strwhile(arr, src);
	j = arr[2];
	if ((int)ft_strlen(str) < num || num == 0)
		num = ft_strlen(str);
	srt = esiminch(num, str);
	srt = strnum(srt, strdes, flags, str);
	dest = valod(num, flags, j);
	dest = foonaem1(strdes, flags, dest);
	srt = foonaem(strdes, flags, srt);
	fooooo1(srt, dest, flags, srt);
	return (1);
}
