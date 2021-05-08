/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:44:10 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/22 13:46:17 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigint(int unsigitoa, char *src, t_flags *flags, char *undest)
{
	char		*str;
	char		*srt;
	char		*dest;
	long int	unsi;

	unsi = 4294967296 + unsigitoa;
	if (unsigitoa < 0)
	{
		str = ft_itoa(unsi / 100000);
		srt = ft_itoa(unsi % 100000);
		dest = ft_strjoin(str, srt);
	}
	else
		dest = ft_itoa(unsigitoa);
	if (((flags->zero - flags->dot == 1) ||
			(flags->dot && undest[flags->dot + 1] == 'u'))
				&& unsigitoa == 0)
		dest = "\0";
	fooooo1(dest, src, flags, dest);
	return (1);
}
