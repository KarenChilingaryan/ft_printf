/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:39:56 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 10:54:58 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*gnlneg(char *str)
{
	char	*src;
	int		i;

	i = 1;
	src = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		src[i - 1] = str[i];
		i++;
	}
	src[i - 1] = '\0';
	return (src);
}

char	*valodik(int c)
{
	int		i;
	char	*src;

	i = 0;
	src = malloc(sizeof(char) * c + 1);
	while (i < c)
		src[i++] = ' ';
	src[i] = '\0';
	return (src);
}

int		ft_percent(char *src, t_flags *flags)
{
	int c;

	if (flags->dot && (flags->width2 || flags->zero))
	{
		free(src);
		c = flags->integer1;
		src = valodik(flags->integer1);
	}
	else if (flags->dot)
	{
		free(src);
		src = malloc(sizeof(char) * 1);
		src[0] = '\0';
	}
	fooooo1("%\0", src, flags, "%\0");
	return (0);
}

char	*flagpointnum(char *str, int *arr, char *dest)
{
	if (str[1] == ' ')
		while (str[arr[0]])
		{
			if (str[arr[0]] == ' ' && str[arr[0] + 2] != ' ')
			{
				str[arr[0]] = '0';
				str[arr[0] + 1] = 'x';
			}
			arr[0]++;
		}
	else
	{
		dest = malloc(sizeof(char) * arr[2] + 2);
		dest[0] = '0';
		dest[1] = 'x';
		while (str[++arr[0]])
			dest[arr[0] + 1] = str[arr[0]];
		dest[arr[0] + 1] = '\0';
		str = dest;
	}
	return (str);
}

char	*flagpointnum1(char *str, int *arr, char *dest)
{
	if (arr[1] <= 2)
		arr[2] = arr[2] + 2 - arr[1];
	dest = malloc(sizeof(char) * arr[2] + 1);
	dest[0] = '0';
	dest[1] = 'x';
	arr[0] = 2;
	while (arr[0] < arr[2])
	{
		dest[arr[0]] = str[arr[0] - 2];
		arr[0]++;
	}
	dest[arr[0]] = '\0';
	str = dest;
	return (str);
}
