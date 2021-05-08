/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:34:54 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/23 12:35:46 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
}

int		ft_atoi(const char *str)
{
	int	i;
	int	negativ;
	int	number;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	negativ = (str[i] == '-') ? -1 : 1;
	if (negativ == -1 || str[i] == '+')
		i++;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + (str[i++] - '0');
	return (number * negativ);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*copy;

	i = 0;
	l = ft_strlen(s1);
	if (!(copy = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
