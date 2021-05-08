/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:47:33 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 10:51:49 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*allfuncsrc(char *str, int *arr, char *src, t_flags *flags)
{
	str[arr[1]++] = '-';
	arr[2] = arr[1] - 1;
	if (!flags->minus && flags->width1 &&
			flags->zero && flags->integer1
				&& !flags->integer2 &&
					!flags->width2 && !flags->dot)
		arr[2] = arr[1];
	while (src[arr[2]])
	{
		str[arr[1]] = src[arr[2]];
		arr[1]++;
		arr[2]++;
	}
	return (str);
}

char	*allfuncsrc1(char *src, char *str, int *arr)
{
	if (src[0] == ' ')
	{
		while (src[arr[1]])
		{
			if (src[arr[1]] == ' ' && src[arr[1] + 1] != ' ')
				str[arr[1]] = '-';
			else
				str[arr[1]] = src[arr[1]];
			arr[1]++;
		}
	}
	else
	{
		str[arr[1]++] = '-';
		while (src[arr[1]])
		{
			str[arr[1]] = src[arr[1] - 1];
			arr[1]++;
		}
	}
	return (src);
}

char	*fooooo1flag(char *src, int *arr, char *str)
{
	while (src[arr[0]])
	{
		if (src[arr[0]] == '0')
		{
			arr[1] = 1;
			while (src[arr[0]] == '0')
				arr[0]++;
			arr[0] = arr[0] - ft_strlen(str);
			if (arr[0] < 0)
				arr[0] = 0;
			while (str[arr[2]])
			{
				src[arr[0]] = str[arr[2]];
				arr[2]++;
				arr[0]++;
			}
			break ;
		}
		arr[0]++;
	}
	return (str);
}

char	*fooooo1arr(int *arr, t_flags *flags, char *src, char *str)
{
	if (flags->zero && flags->integer1 < 0)
		flags->minus = -1;
	if (!arr[1])
	{
		if (flags->minus == 0)
			arr[0] = ft_strlen(src) - ft_strlen(str);
		else
			arr[0] = 0;
		arr[2] = 0;
		while (str[arr[2]])
			src[arr[0]++] = str[arr[2]++];
	}
	return (str);
}

int		fooooo1(char *str, char *src, t_flags *flags, char *line)
{
	int arr[3];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
		str = gnlneg(str);
	if (ft_strlen(str) < ft_strlen(src))
		fooooo1flag(src, arr, str);
	else
	{
		flags->len += (int)ft_strlen(line);
		ft_putstr_fd(line, 1);
		return (1);
	}
	fooooo1arr(arr, flags, src, str);
	if (flags->negative)
		src = negativestr(src, flags);
	flags->len += (int)ft_strlen(src);
	ft_putstr_fd(src, 1);
	return (1);
}
