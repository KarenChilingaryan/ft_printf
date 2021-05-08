/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:27:44 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/22 13:38:57 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbrx(unsigned long long intx,
					char c, char **line, t_flags *flags)
{
	char	*str;

	str = NULL;
	if (((flags->zero - flags->dot == 1) ||
			(flags->dot && (line[1][flags->dot + 1] == 'x'
				|| line[1][flags->dot + 1] == 'X'))) && intx == 0)
		str = "\0";
	else if (intx == 0)
		str = "0\0";
	else if (c == 'x')
		str = ft_putnbr_base_pointer(intx, 87);
	else if (c == 'X')
		str = ft_putnbr_base_pointer(intx, 55);
	fooooo1(str, line[0], flags, str);
	return (1);
}
