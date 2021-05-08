/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:17:24 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/22 14:46:11 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(char c, char *src, t_flags *flags)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	if (c == '\0' && flags->integer1)
	{
		src[(int)ft_strlen(src) - 1] = '\0';
		flags->len++;
		if (flags->minus == -1)
			ft_putchar_fd('\0', 1);
		fooooo1(str, src, flags, str);
		if (flags->minus == 0)
			ft_putchar_fd('\0', 1);
	}
	else if (c == '\0')
	{
		ft_putchar_fd('\0', 1);
		flags->len++;
	}
	else
		fooooo1(str, src, flags, str);
	return (1);
}
