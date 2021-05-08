/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:24:30 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/22 13:27:34 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zerowidth(int c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (c * -1) + 1);
	while (i < (c * -1))
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*intnum(char *dest, char *src, t_flags *flags)
{
	if (dest[flags->zero - 1] == '%' && (dest[flags->width1 + 1] == 'i'
		|| dest[flags->width1 + 1] == 'd') && flags->width1 - flags->zero
			== 1 && flags->integer1 < 0)
	{
		src = zerowidth(flags->integer1);
		flags->minus = -1;
		flags->integer1 *= -1;
		flags->zero = 0;
	}
	return (src);
}

int		ft_int(int intitoa, char *src, t_flags *flags, char *dest)
{
	char *str;
	char *line;

	line = ft_itoa(intitoa);
	if (intitoa < 0)
	{
		flags->negative = 1;
		intitoa = -1 * intitoa;
	}
	else
		flags->negative = 0;
	if (((flags->zero - flags->dot == 1) ||
			(flags->dot && (dest[flags->dot + 1] == 'i'
				|| dest[flags->dot + 1] == 'd'))) && intitoa == 0)
	{
		line = "\0";
		str = "\0";
	}
	else
		str = ft_itoa(intitoa);
	src = intnum(dest, src, flags);
	fooooo1(str, src, flags, line);
	return (1);
}
