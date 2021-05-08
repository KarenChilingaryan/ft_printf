/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsiglong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:32 by kchiling          #+#    #+#             */
/*   Updated: 2021/03/26 10:50:22 by kchiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malloc(unsigned int nbr)
{
	int		count;
	char	*str;

	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	return (str);
}

char	*ft_mallocflag(unsigned long long nbr)
{
	int		count;
	char	*str;

	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	return (str);
}

char	*ft_putnbr_base_pointer(unsigned int nbr, int c)
{
	char			*rtn;
	int				count;
	unsigned int	save;

	save = nbr;
	rtn = ft_malloc(nbr);
	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	rtn[count] = '\0';
	while (save != 0)
	{
		if ((save % 16) < 10)
			rtn[count - 1] = (save % 16) + 48;
		else
			rtn[count - 1] = (save % 16) + c;
		save /= 16;
		count--;
	}
	return (rtn);
}

char	*ft_putnbr_base_pointerflag(unsigned long long nbr, int c)
{
	char				*rtn;
	int					count;
	unsigned long long	save;

	save = nbr;
	rtn = ft_mallocflag(nbr);
	count = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	while (save != 0)
	{
		if ((save % 16) < 10)
			rtn[count - 1] = (save % 16) + 48;
		else
			rtn[count - 1] = (save % 16) + c;
		save /= 16;
		count--;
	}
	return (rtn);
}
