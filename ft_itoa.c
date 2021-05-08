/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:35:04 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/23 12:35:06 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n = n * -1;
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;
	int		m;
	long	nbr;

	m = 0;
	nbr = n;
	l = length(nbr);
	str = malloc(l * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	str[l] = '\0';
	if (nbr < 0)
	{
		m = 1;
		nbr = nbr * -1;
	}
	while (l--)
	{
		str[l] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (m)
		str[0] = '-';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(1 + (ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		else
		{
			dest[i + j] = s2[j];
			j++;
		}
	}
	dest[i + j] = '\0';
	return (dest);
}
