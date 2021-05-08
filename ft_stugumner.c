/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stugumner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:01:37 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 10:58:00 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filters(int s, t_flags *flags, char *str, char *dest)
{
	int arr[3];

	arr[2] = s;
	if (flags->integer1 < 0)
		arr[1] = flags->integer1 * -1;
	else
		arr[1] = flags->integer1;
	arr[0] = 0;
	while (arr[0] < arr[2])
	{
		dest[arr[0]] = stugdest(flags, dest, str, arr);
		arr[0]++;
	}
	dest[arr[0]] = '\0';
}

char	*createstr(t_flags *flags, char *str)
{
	char	*dest;
	int		s;
	int		m;

	if (str[flags->width1 - 1] == '.' && flags->integer1 < 0)
		m = 0;
	else if (flags->integer1 < 0)
		m = flags->integer1 * -1;
	else
		m = flags->integer1;
	if (m > flags->integer2)
		s = m;
	else
		s = flags->integer2;
	if (!(dest = malloc(sizeof(char) * s + 1)))
		return (0);
	filters(s, flags, str, dest);
	return (dest);
}

void	flagdata(t_flags *flags, va_list args, char *str, int i)
{
	if (!flags->width1)
	{
		flags->width1 = i;
		flags->integer1 = va_arg(args, int);
		if (flags->integer1 < 0 && (str[flags->width1 - 1] == '-'
					|| str[flags->width1 - 1] == '%'))
		{
			flags->minus = -1;
			flags->integer1 = flags->integer1 * -1;
		}
	}
	else
	{
		flags->width2 = i;
		flags->integer2 = va_arg(args, int);
	}
}

int		flagname1(t_flags *flags, char *str, int i)
{
	if (!flags->width1)
	{
		flags->width1 = i;
		flags->integer1 = ft_atoi(&str[i]);
		i += ft_strlen(ft_itoa(flags->integer1)) - 1;
	}
	else
	{
		flags->width2 = i;
		flags->integer2 = ft_atoi(&str[i]);
		i += ft_strlen(ft_itoa(flags->integer2)) - 1;
	}
	return (i);
}

int		ft_charsimbol(int i, t_flags *flags, va_list args, char *str)
{
	char *src;

	src = NULL;
	if (str[i] == '-')
		flags->minus = -1;
	else if ((str[i] == '0' && str[i + 1] != '-') ||
			(str[i] == '0' && str[i + 1] == '*'))
		flags->zero = i;
	else if (str[i] == '.')
		flags->dot = i;
	else if (str[i] == '*')
		flagdata(flags, args, str, i);
	else if (str[i] > '0' && str[i] <= '9')
		i = flagname1(flags, str, i);
	return (i + 1);
}
