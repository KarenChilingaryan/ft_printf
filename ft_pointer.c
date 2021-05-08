/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:42:04 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 11:08:51 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pointdest(char *src, int *arr, char *str)
{
	while (src[arr[0]])
	{
		if (src[arr[0]] == '0')
		{
			arr[2] = 1;
			while (src[arr[0]] == '0')
				arr[0]++;
			arr[0] = arr[0] - ft_strlen(str);
			if (arr[0] < 0)
				arr[0] = 0;
			while (str[arr[1]])
			{
				src[arr[0]] = str[arr[1]];
				arr[1]++;
				arr[0]++;
			}
			break ;
		}
		arr[0]++;
	}
	return (src);
}

char	*pointer(char *str, char *src, t_flags *flags, char *line)
{
	int arr[3];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if (ft_strlen(str) < ft_strlen(src))
		src = pointdest(src, arr, str);
	else
		return (line);
	if (!arr[2])
	{
		if (flags->minus == 0)
			arr[0] = ft_strlen(src) - ft_strlen(str);
		else
			arr[0] = 0;
		arr[1] = 0;
		while (str[arr[1]])
			src[arr[0]++] = str[arr[1]++];
	}
	return (src);
}

int		flagpointer(char *str, t_flags *flags)
{
	char	*dest;
	int		arr[3];

	dest = NULL;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = (int)ft_strlen(str);
	while (str[arr[0]])
		if (str[arr[0]++] == ' ')
			arr[1]++;
	arr[0] = 0;
	if (str[0] == ' ')
		str = flagpointnum(str, arr, dest);
	else
		str = flagpointnum1(str, arr, dest);
	flags->len += ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (1);
}

char	*pointerflag(char *str, t_flags *flags, char *dest, int *arr)
{
	if (flags->integer1 && flags->integer2)
		flagpointer(str, flags);
	else if ((flags->integer1 && !flags->integer2 &&
				dest[flags->dot - 1] == '%') || (!flags->minus
					&& !flags->width1 && !flags->zero
						&& !flags->width2 && !flags->dot))
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		flags->len += 2 + ft_strlen(str);
	}
	else if (flags->integer1 && !flags->integer2
				&& dest[flags->zero - 1] == '%')
	{
		if (str[arr[0]] == '0')
			arr[0]++;
		if (str[arr[0]] == '0')
			arr[0]++;
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(&str[arr[0]], 1);
		flags->len += 2 + ft_strlen(&str[arr[0]]);
	}
	else
		flagpointer(str, flags);
	return (str);
}

int		ft_pointer(unsigned long long address, char *src,
		t_flags *flags, char *dest)
{
	char	*str;
	int		arr[1];

	arr[0] = 0;
	if (((flags->zero - flags->dot == 1) ||
			(flags->dot && dest[flags->dot + 1] == 'p'))
				&& address == 0)
		fooooo1("0x", src, flags, "0x");
	else if (address == 0)
	{
		str = pointer("0\0", src, flags, "0\0");
		flagpointer(str, flags);
	}
	else
	{
		str = ft_putnbr_base_pointerflag(address, 87);
		str = pointer(str, src, flags, str);
		pointerflag(str, flags, dest, arr);
	}
	return (1);
}
