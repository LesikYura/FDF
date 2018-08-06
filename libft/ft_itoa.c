/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:48:10 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 15:48:48 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	nbr_to_char(int n)
{
	int	nb;

	if (n >= 0 && n <= 9)
		return (n + '0');
	else
	{
		nbr_to_char(n / 10);
		nb = n % 10;
		return (my_abs(nb) + '0');
	}
	return ('\0');
}

static	int		my_strln(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		ln;
	char	*c;

	ln = my_strln(n);
	if (n < 0)
	{
		if (!(c = ft_strnew(++ln)))
			return (NULL);
		c[0] = '-';
	}
	else
	{
		if (!(c = ft_strnew(ln)))
			return (NULL);
		c[0] = '0';
	}
	while (ln > 0 && n)
	{
		c[--ln] = nbr_to_char(n);
		n = n / 10;
	}
	return (c);
}
