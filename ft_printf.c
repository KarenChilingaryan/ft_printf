/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:32:05 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/22 16:32:10 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width1 = 0;
	flags.width2 = 0;
	flags.integer1 = 0;
	flags.integer2 = 0;
	flags.negative = 0;
	flags.len = 0;
	flags.type = 'l';
	return (flags);
}

void		charwrite(int c, t_flags *flags)
{
	write(1, &c, 1);
	flags->len++;
}

int			inputelem(t_flags *flags, char *str, va_list args, int i)
{
	if (str[i - 1] != '%')
		charwrite(str[i - 1], flags);
	else if (charelem(str[i]))
	{
		while (charelem(str[i]))
			i = ft_charsimbol(i, flags, args, str);
		if (ft_charletter(str[i]))
			i = stugum(str, args, i, flags);
		return (i);
	}
	else if (ft_charletter(str[i]))
		return (stugum(str, args, i, flags));
	else if (str[i] != '%')
		charwrite(str[i++], flags);
	else
		charwrite(str[i++], flags);
	return (i);
}

int			foo(char *str, va_list args)
{
	int		i;
	t_flags	flags;
	int		len;

	i = 0;
	len = 0;
	flags = ft_init_flags();
	while (str[i] && i != -1)
	{
		flags = ft_init_flags();
		i = inputelem(&flags, str, args, i + 1);
		len += flags.len;
	}
	return (len);
}

int			ft_printf(const char *input, ...)
{
	char	*rezerv;
	va_list	args;
	int		i;

	rezerv = NULL;
	rezerv = ft_strdup(input);
	va_start(args, input);
	i = foo(rezerv, args);
	va_end(args);
	free((char *)rezerv);
	return (i);
}
