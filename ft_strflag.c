/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:16:20 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 11:34:39 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*space(int c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * c + 1);
	while (i < c)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*esiminch(int n, char *str)
{
	char	*ghn;
	int		i;

	i = -1;
	ghn = malloc(sizeof(char) * n + 1);
	while (++i < n)
		ghn[i] = str[i];
	ghn[i] = '\0';
	return (ghn);
}

char	*foonaem(char *strdes, t_flags *flags, char *srt)
{
	if ((((strdes[flags->dot + 1] == 's' && flags->integer1) ||
		(strdes[flags->dot + 1] == '0' && strdes[flags->dot + 2]
			== 's')) || (!flags->width1 && !flags->width2 &&
				flags->zero && flags->dot)) && !flags->width2)
		srt = "\0";
	return (srt);
}

char	*foonaem1(char *strdes, t_flags *flags, char *dest)
{
	if (strdes[flags->zero - 1] == '%' &&
			flags->width1 - flags->zero == 1 && !flags->width2)
		dest = zeroflag(flags->integer1);
	return (dest);
}

char	stugdest(t_flags *flags, char *dest, char *str, int *arr)
{
	if (flags->width1 && !flags->width2 &&
			flags->zero && !flags->dot && !flags->minus)
		dest[arr[0]] = '0';
	else if (arr[1] > flags->integer2 && arr[0] < arr[2] - flags->integer2 &&
			flags->minus == 0 && (str[flags->width1 - 1] == '%' ||
				(str[flags->width1 - 1] == '0' &&
					str[flags->width1 - 2] == '%' && (flags->integer2
						|| str[flags->dot + 1] == '0'))))
		dest[arr[0]] = ' ';
	else if (arr[1] > flags->integer2 &&
			arr[0] < flags->integer2 && flags->minus == -1)
		dest[arr[0]] = '0';
	else if (arr[1] > flags->integer2 &&
			arr[0] >= arr[2] - arr[1] && flags->minus == -1
				&& str[flags->dot - 1] != '-')
		dest[arr[0]] = ' ';
	else if (flags->width1 && !flags->width2 &&
				flags->zero && !flags->dot && flags->minus)
		dest[arr[0]] = ' ';
	else
		dest[arr[0]] = '0';
	return (dest[arr[0]]);
}
